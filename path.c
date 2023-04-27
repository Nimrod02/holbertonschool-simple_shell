#include "main.h"

/**
 * path_ - find a path
 * @path: the path to find
 *
 * Return: 1 (relative) or 0 (absolute)
*/

int path_(char *path)
{
	if (strlen(path) > 3)
	{
		if ((path[0] == '.' && path[1] == '/') || path[0] == '/' ||
			(path[0] == '.' && path[1] == '.' && path[2] == '/'))
			return (1);
	}
	return (0);
}

/**
 * pathmatch - fide a directory in path
 * @executable: executable name
 *
 * Return: path of executable or NULL if not found
*/

char *pathmatch(char **executable)
{
	char **array;
	char *tmp, *path;
	int index = 0;
	struct stat st;

	path = getenv("PATH");

	if (strlen(path) == 0)
		return (NULL);

	array = split(path, ':');

	if (!array)
		return (NULL);

	while (array[index] != NULL)
	{
		tmp = makepath_(array[index], *executable);

		if (stat(tmp, &st) == 0)
		{
			free(*executable);
			*executable = tmp;
			freearray(array);
			return (tmp);
		}
		free(tmp);
		index++;
	}
	freearray(array);
	return (NULL);
}

/**
 * makepath_ - make a path to a file
 * @path: path to the directory
 * @file: the file
 *
 * Return: the new path
*/

char *makepath_(char *path, char *file)
{
	char *npath;

	if (file == NULL || path == NULL)
		return (NULL);

	npath = malloc(sizeof(char) *
		(strlen(path) + strlen(file) + 2));

	if (!npath)
		return (NULL);

	strcpy(npath, path);
	npath[strlen(path)] = '/';
	npath[strlen(path) + 1] = '\0';
	strcat(npath, file);

	return (npath);
}
