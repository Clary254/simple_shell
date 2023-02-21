#include <stdio.h>
#include <stddef.h>
#include "shell.h"

/**
  * _exit_shell - exists shell session
  * @env: current environment variables
  * @args: arguments passed from user
  * Return: Always return 0
  */

int _exit_shell(char **env, char **args)
{
	(void)env;
	(void)args;

	printf("\nExiting...\n");
	return (0);
}

/**
  * print_env - prints the current environment
  * @env: current environment variables
  * @args: arguments passed from user
  * Return: Always return 1 on success
  */

int print_env(char **env, char **args)
{
	int x = 0;
	(void)args;

	while (env[x] != NULL)
	{
		printf("%s\n", env[x]);
		x++;
	}

	return (1);
}

/**
  * get_builtin_func - gets the correct function according to passed in param
  * @fname: name of function
  * Return: builtin_function if found otherwise NULL
  */

builtin_function get_builtin_func(char *fname)
{
	int x = 0;
	struct_builtin f_array[] = {
		{"exit", &_exit_shell},
		{"env", &print_env},
		{NULL, NULL}
	};

	while (f_array[x].name != NULL)
	{
		if (isstring(f_array[x].name, fname))
		{
			return (f_array[x].b_function);
		}
		x++;
	}

	return (NULL);
}

