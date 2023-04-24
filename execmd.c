#include "main.h"

void execmd(char **argv)
{
	char *command = NULL, *exec_command = NULL;

	if (argv)
	{
		command = argv[0];

		exec_command = get_location(command);

		if (execve(exec_command, argv, NULL) == -1)
			perror("error");
	}
}
