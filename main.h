#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

/**
 * struct builtin - shell's builtin or function
 * @s: name of builtin or function
 * @f: what the builtin or function does
*/
typedef struct builtin
{
	char *s;
	int (*f)(char **av);
} builtin;

#endif
