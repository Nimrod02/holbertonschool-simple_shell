#include "main.h"

/**
 * executefunction - execute
 * @av: the array of argument from command line
 *
 * Return: the function or 0
*/
int executefunction(char **av)
{
	builtin builtins[] = {
		{"exit", fexit},
		{"env", _env},
		{NULL, NULL}
	};
	int index = 0;

	while (builtins[index].cmd)
	{
		if (strcmp(builtins[index].cmd, av[0]) == 0)
			return (builtins[index].func(av));

		index++;
	}
	return (0);
}

/**
 * forkcmd - fork the execute command in a child process using execve
 * @command: the command to execute
 * @av: an array of arguments for the command
 *
 * Return: 0 on success, -1 on failure
 */
int forkcmd(char *command, char **av)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		if (execve(command, av, NULL) == -1)
		{
		perror("error");
		exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("error");
		return (-1);
	}

	return (0);
}

/**
 * executecmd - execute a line of command
 * @line: the line of command
 *
 * Return: 0 on success, -1 on failure
*/
int executecmd(char *line)
{
	char **av, **lines;
	int index = 0, success = 0;
	char *command = NULL, *exec_command = NULL;

	line[strlen(line) - 1] = '\0';
	lines = split(line, ';');
	free(line);

	while (lines[index])
	{
		av = split(lines[index], ' ');
		index++;

		if (av != NULL)
		{
			if (!strcmp(av[0], "exit"))
				freearray(lines);

			if (!executefunction(av))
			{
				command = av[0];

				exec_command = get_location(command);

				success = forkcmd(exec_command, av);

				free(exec_command);
			}
		}
	}
	return (success);
}
