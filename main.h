#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

char *get_location(char *command);
void execmd(char **argv);
void promptloop(int input);
int main(void);

/**
 * struct builtin - shell's builtin or function handmade
 * @s: name of builtin or function
 * @f: what the builtin or function does
*/
typedef struct builtin
{
	char *cmd;
	int (*func)(char **av);
} builtin;

void freearray(char **array);
int fexit(char **av);
void executecmd(char *line);
void *nrealloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **split(const char *str, const char del);
int _env(char **av __attribute__((unused)));

#endif
