#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/**
 * struct builtin - shell's builtin or function handmade
 * @cmd: name of builtin or function
 * @func: what the builtin or function does
*/
typedef struct builtin
{
	char *cmd;
	int (*func)(char **av);
} builtin;

char *get_location(char *command);
void promptloop(int input);
int main(void);
void freearray(char **array);
int fexit(char **av);
int executecmd(char *line);
void *nrealloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **split(const char *str, const char del);
int _env(char **av __attribute__((unused)));

#endif
