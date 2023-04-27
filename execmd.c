#include "main.h"

/**
 * executefunction - give the function for a string
 * @av: the array of argument from command line
 *
 * Return: the function or 0
*/
int executefunction(char **av)
{
	builtin builtins[] = {
		{"exit", exit_},
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
 *
 * Return: 0 on success, -1 on failure
*/
void executecmd(char *line)
{
	char **av, **lines;
	char *a;
	int index = 0;


	line[strlen(line) - 1] = '\0';
	lines = split(line, ';'); /* Handle the ';' separator */
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
				a = strdup(av[0]);

				if (path_(av[0]) || pathmatch(&av[0]))
					make_fork(av);

				else
					showerror(av[0], "not found\n");

				free(a);
			}
		freearray(av);
		}
	}
	freearray(lines);
}

/**
 * make_fork - for and run prog with parameters
 * @av: array containing the program and it's parameters
 *
 * Return: value of child proccess
*/

int make_fork(char **av)
{
	pid_t my_pid, child;
	int wstatus;

	child = fork();

	if (child == -1)
		perror("hsh");

	if (child == 0)
	{
		my_pid = execve(av[0], av, environ);

		if (my_pid == -1)
			exit(1);

	}
	else
		wait(&wstatus);

	return (WEXITSTATUS(wstatus));

}

/**
 * showerror - print a personalized error message
 * @name: name of the thing producing an error
 * @error: error text to print
*/
void showerror(char *name, char *error)
{
	write(STDOUT_FILENO, "hsh: ", 5);
	write(STDOUT_FILENO, name, strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, error, strlen(error));
}
