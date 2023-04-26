#include "main.h"

/**
 * _env - print the environment
 * @av: array of argument
 *
 * Return: 1 or 2
*/

int _env(char **av __attribute__((unused)))
{
	int index = 0;

	while (environ[index])
	{
		if (write(STDOUT_FILENO, environ[index], strlen(environ[index])) == -1)
		{
			perror("env");
			return (2);
		}
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	return (1);
}
