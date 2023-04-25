#include "main.h"

/**
 * split - split a string into tokens using a delimeter
 * @str: the string
 * @del: the delimeter
 *
 * Return: array of strings like strtok
 **/

char **split(const char *str, const char del)
{
	char **nstr = NULL;
	int index = 0, j, k = 0;

	while (str[index] != '\0' && str[index] == del)
		index++;

	if (!str[index])
		return (NULL);

	index = 0;
	while (str[index])
	{
		j = index;
		if (str[index] != del)
		{
			nstr = nrealloc(nstr, sizeof(char *) * k,
						 sizeof(char *) * (k + 1));
			nstr[k] = NULL;
			while (str[j] && str[j] != del)
			{
				nstr[k] = nrealloc(nstr[k], (j - index), ((j - index) + 1));
				nstr[k][j - index] = str[j];
				j++;
			}
			nstr[k] = nrealloc(nstr[k], (j - index), ((j - index) + 1));
			nstr[k][j - index] = '\0';
			index += (j - index);
			k++;
		}
		else
			index++;

	}
	nstr = nrealloc(nstr, sizeof(char *) * k, sizeof(char *) * (k + 1));
	nstr[k] = NULL;

	return (nstr);
}

/**
 * nrealloc - realloc function like realloc
 * @ptr: pointer to array
 * @old_size: old size of said array
 * @new_size: new size of said array
 *
 * Return: the realloc array
 **/

void *nrealloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		return (nptr);
	}
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	nptr = malloc(old_size + (new_size - old_size));
	memcpy(nptr, ptr, old_size);
	free(ptr);

	return (nptr);
}
