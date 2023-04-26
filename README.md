
# <p align="Center">C - Simple Shell</p>
```

                       _____ _   _ _____    ____    _  _____ _____ ____     ___  _____
                      |_   _| | | | ____|  / ___|  / \|_   _| ____/ ___|   / _ \|  ___|
                        | | | |_| |  _|   | |  _  / _ \ | | |  _| \___ \  | | | | |_
                        | | |  _  | |___  | |_| |/ ___ \| | | |___ ___) | | |_| |  _|
                        |_| |_| |_|_____|  \____/_/   \_\_| |_____|____/   \___/|_|

                                       ____  _   _ _____ _     _
                                      / ___|| | | | ____| |   | |
                                      \___ \| |_| |  _| | |   | |
                                       ___) |  _  | |___| |___| |___
                                      |____/|_| |_|_____|_____|_____|

```
## HSH : Holberton Simple Shell
The simple shell is a Holberton School project in the first trimester, helps student to understand the advanced concepts behind the shell program include process. <br>
Simple Shell is a simple command line prompt that takes the most basics of commands that are present in the bash shell and runs them. <br>
Program include: system call, bit manipulation, file managment, error handling ...

## Syntax
The shell works by using commands given by the user input. The shell commands take in the following syntax: `command name` `{arguments}`. The shell executes a command after it is written by user using the command followed by the arguments.<br><br>
`cat execmd.c` The above example takes in a command by the user followed with the arguments. In this case the command is cat (to view file without opening file) followed by argument the file name in this case `execmd.c`.<br><br>
For more information on `cat`, you can use the `man` command which will show a manual of the given command or any command you wish to know more information on. It contains system calls, libraries and other important files.<br><br>
The shell also contains two builtins which are commands that are within the shell itself. The two builtins are `exit` and `env`. You can also use `help` command to know which builtins are provided by the shell. The `help command` works similarly to the manual where it provides further detail or information on given builtin.<br><br>

## Compilation
The shell works by being compiled using **GCC version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)** compiler or later versions. The shell can compile using: <br>

| **Compile and Run** |
|-----------------|
| gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh && ./hsh |
<img src="https://www.zupimages.net/up/23/17/elxb.png" width="800\"/>

## List of useful commands
| **Command** | **Description** |
|-----------------| -----------------|
|cat| Allowing to concatenate files as well as to display their contents on the standard output |
|less| Allowing to view a text file|
|touch| Create a new File |
|mkdir| Create a new Directory |
|ls| The ls command displays the contents of the current Directory|
|cp| Allowing to copy Files and Directories. |
|mv| Allows to move a File, Directory or any tree on Linux |
|pwd| Allows to display the path of the current directory |
|grep| Allows you to search for a file or a set of files based on an expression contained in the file or files.|
|Exit| Allows you to exit the terminal |

Exemple Output :
```
codespace ➜ ~/holbertonschool-simple_shell (development) $ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
codespace ➜ ~/holbertonschool-simple_shell (development) $ ./hsh
$ pwd
/home/codespace/holbertonschool-simple_shell
$ ls
README.md  Test  Tests  dossierScript  env.c  execmd.c  exit.c  get_location.c  hsh  main.c  main.h  split_str.c
$ ls -a
.  ..  .git  .gitignore  .vscode  README.md  Test  Tests  dossierScript  env.c  execmd.c  exit.c  get_location.c  hsh  main.c  main.h  split_str.c
$ ls -lna
total 96
drwxr-sr-x 7 1000 1000  4096 Apr 26 12:57 .
drwxrwsr-x 1 1000 1000  4096 Apr 26 08:20 ..
drwxr-sr-x 8 1000 1000  4096 Apr 26 12:05 .git
-rw-r--r-- 1 1000 1000   589 Apr 26 08:26 .gitignore
drwxr-sr-x 2 1000 1000  4096 Apr 18 16:37 .vscode
-rw-r--r-- 1 1000 1000 10415 Apr 26 12:45 README.md
drwxr-sr-x 2 1000 1000  4096 Apr 26 08:27 Test
drwxr-sr-x 2 1000 1000  4096 Apr 24 08:44 Tests
drwxr-sr-x 2 1000 1000  4096 Apr 26 08:31 dossierScript
-rw-r--r-- 1 1000 1000   373 Apr 26 08:28 env.c
-rwxr-xr-x 1 1000 1000  1528 Apr 26 08:28 execmd.c
-rw-r--r-- 1 1000 1000   513 Apr 26 08:28 exit.c
-rw-r--r-- 1 1000 1000  1002 Apr 26 08:24 get_location.c
-rwxr-xr-x 1 1000 1000 18248 Apr 26 12:57 hsh
-rwxr-xr-x 1 1000 1000   551 Apr 26 08:28 main.c
-rw-r--r-- 1 1000 1000   769 Apr 26 08:28 main.h
-rw-r--r-- 1 1000 1000  1501 Apr 26 08:28 split_str.c
$
```

## Bugs and error
- Directional arrows
> If you use the arrow keys on your keyboard to move the cursor, you will notice that a small bug occurs
Some characters are displayed at the location of your cursor.
```
Up Arrow ^[[A
Down Arrow ^[[B
Right Arrow ^[[C
Left Arrows ^[[D
```
<img src="https://www.zupimages.net/up/23/17/3g1i.png" width="600\"/>

--------------------


## Programs Files
### [env.c](https://github.com/xdJidx/holbertonschool-printf/blob/main/_printf.c)
- Function that print the current environment.
<details>
<summary>File</summary>

```c
#include "main.h"

/**
 * _env - print the environment
 * @av: array of argument
 *
 * Return: 1 or 2
*/

int _env(char **av __attribute__((unused)))
{
	int index = 0;

	while (environ[index])
	{
		if (write(STDOUT_FILENO, environ[index], strlen(environ[index])) == -1)
		{
			perror("env");
			return (2);
		}
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	return (1);
}
```
</details>

--------------------

### [execmd.c](https://github.com/xdJidx/holbertonschool-printf/blob/main/_putchar.c)
- Contains 3 Functions
	- `executefunction` : Execute the builtin function.
	- `forkcmd` : Function that lets the infinite loop (parent) continue while the command execution runs (child).
	- `executecmd` : Function that allows the execution of the command taken in the input.
<details>
<summary>File</summary>

```c
#include "main.h"

/**
 * executefunction - execute
 * @av: the array of argument from command line
 *
 * Return: the function or 0
*/
int executefunction(char **av)
{
	builtin builtins[] = {
		{"exit", fexit},
		{"env", _env},
		{NULL, NULL}
	};
	int index = 0;

	while (builtins[index].cmd)
	{
		if (strcmp(builtins[index].cmd, av[0]) == 0)
			return (builtins[index].func(av));

		index++;
	}
	return (0);
}

/**
 * forkcmd - fork the execute command in a child process using execve
 * @command: the command to execute
 * @av: an array of arguments for the command
 *
 * Return: 0 on success, -1 on failure
 */
int forkcmd(char *command, char **av)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		if (execve(command, av, NULL) == -1)
		{
		perror("error");
		exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("error");
		return (-1);
	}

	return (0);
}

/**
 * executecmd - execute a line of command
 * @line: the line of command
*/
int executecmd(char *line)
{
	char **av, **lines;
	int index = 0, success = 0;
	char *command = NULL, *exec_command = NULL;

	line[strlen(line) - 1] = '\0';
	lines = split(line, ';');
	free(line);

	while (lines[index])
	{
		av = split(lines[index], ' ');
		index++;

		if (av != NULL)
		{
			if (!strcmp(av[0], "exit"))
				freearray(lines);

			if (!executefunction(av))
			{
				command = av[0];

				exec_command = get_location(command);

				success = forkcmd(exec_command, av);

				free(exec_command);
			}
		}
	}
	return (success);
}
```
</details>

--------------------

### [exit.c](https://github.com/xdJidx/holbertonschool-printf/blob/main/_vsprintf.c)
- Contain 2 Functions
	- `freearray` : Function that frees a double pointer.
	- `fexit` : Function that exits the program (simple shell) with a precise status.
<details>
<summary>File</summary>

```c
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
```
</details>

--------------------

### [get_location.c](https://github.com/xdJidx/holbertonschool-printf/blob/main/main.h)
- Function that goes through all the paths of the environment to find the corresponding command.
<details>
<summary>File</summary>

```c
#include "main.h"
/**
 * get_location - find location of the command in a PATH
 * @command: given command from the input
 *
 * Return: the command to be execute
*/
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
```
</details>

--------------------

### [main.c](https://github.com/xdJidx/holbertonschool-printf/blob/main/string_spe.c)
- Main Function that displays and takes intputs.
<details>
<summary>File</summary>

```c
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

	do
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
	} while (1);
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
```
</details>

--------------------

### [main.h](https://github.com/xdJidx/holbertonschool-printf/blob/main/string_spe.c)
- Our header file that contains all the library, prototype and structure use in this project.
<details>
<summary>File</summary>

```h
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
 * @s: name of builtin or function
 * @f: what the builtin or function does
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
```
</details>

--------------------

### [split.c](https://github.com/xdJidx/holbertonschool-printf/blob/main/string_spe.c)
- Contain 2 Functions
	- `split` : split a string into tokens using a delimeter
	- `nrealloc` : function that reallocates a new size of memory to the pointer who needs it
<details>
<summary>File</summary>

```c
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
```
</details>

------------------------------

# Author
ROGERET Kevin : **[Air-KS](https://github.com/Air-KS).** <br>
> Project carried out within the framework of the school **[Holberton School](https://www.holbertonschool.com/).**<br>


