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
 * exit_ - exit the shell
 * @array: array of arguments
 *
 * Return: 2
*/

int exit_(char **array)
{
	int status;
	/*if no status just exit*/
	if (array[1] == NULL)
	{
		freearray(array);
		exit(0);
	}
	/*if status present convert str into int*/
	else
	{
		status = atoi(array[1]);
		freearray(array);
		exit(status);
	}

	return (2);
}
