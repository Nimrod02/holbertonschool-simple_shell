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

void promptloop(int input);
int main(void);
void freearray(char **array);
int exit_(char **av);
void executecmd(char *line);
void *nrealloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **split(const char *str, const char del);
int _env(char **av __attribute__((unused)));
int path_(char *path);
char *makepath_(char *path, char *file);
int make_fork(char **av);
void showerror(char *name, char *error);
char *pathmatch(char **executable);

#endif
