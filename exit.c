#include "main.h"

/**
 * freearray - free an array
 * @array: the array
*/

void freearray(char **array)
{
	int index = 0;

	while (array[index])
		free(array[index++]);

	free(array);
}

/**
 * _exit - exit the shell
 * @av: array of arguments
 *
 * Return: 2
*/

int fexit(char **av)
{
	int status;
	/*if no status just exit*/
	if (av[1] == NULL)
	{
		freearray(av);
		exit(0);
	}
	/*if status present convert str into int*/
	else
	{
		status = atoi(av[1]);
		freearray(av);
		exit(status);
	}

	return (2);
}
