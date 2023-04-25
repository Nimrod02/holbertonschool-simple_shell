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
 * executecmd - execute a line of command
 * @line: the line of command
*/
void executecmd(char *line)
{
	char **av, **lines;
	int index = 0;
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

				if (execve(exec_command, av, NULL) == -1)
					perror("error");
			}
		}
	}
}
