#include "main.h"

/**
 * promptloop - loop for the prompt
 * @input: isatty(STDIN_FILENO)
*/

void promptloop(int input)
{
	char *lineptr = NULL;
	size_t c = 0;
	ssize_t a = 0;

	while (1)
	{
		if (input)
			write(STDOUT_FILENO, "$ ", 2);

		a = getline(&lineptr, &c, stdin);

		if (a == EOF)
		{
			free(lineptr);
			exit(0);
		}
	 	if (strcmp(lineptr, "\n"))
		{
			executecmd(lineptr);
			lineptr = NULL;
		}
	}
}

/**
 * main - main function
 *
 * Return: 0 on success
 **/
int main(void)
{

	promptloop(isatty(STDIN_FILENO));

	return (0);
}

