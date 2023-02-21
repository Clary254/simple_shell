#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"
/**
  * _getline - read user input
  * @str: pointer to string
  * @bufsize: size of str
  * Description: puts the read input into the str argument;
  * Return: return number of characters read or -1 if nothing read
  */

size_t _getline(char *str, size_t *bufsize)
{
	ssize_t n;

	n = getline(&str, bufsize, stdin);

	if (n == -1)
	{
		if (errno != EOF)
		{
			exit(EXIT_SUCCESS);
		} else
		{
			exit(EXIT_FAILURE);
		}
	}

	return (n);
}

/**
  * setargs - create a null terminated array of strings
  * @tokens: array of strings
  * @str: string to tokenize
  * Return: void
  */

char **setargs(char **tokens, char *str)
{
	char *token;
	int position = 0;
	char *delim = "/ ";
	char *delim2 = " ";

	if (ispath(str))
	{
		token = strtok(str, delim);
		token = strtok(NULL, delim);
	} else
	{
		token = strtok(str, delim);
	}
	while (token != NULL)
	{
		tokens[position] = token;
		token = strtok(NULL, delim2);
		position++;
	}
	tokens[position] = NULL;
	return (tokens);
}
/**
  * get_exe_path - converts executable path var in env to array
  * @exepath: points to array that will hold all executable paths
  * @env: environment array
  * Return: 1
  */

int get_exe_path(char **exepath, char **env)
{
	char *token, *buffer;
	int path = -1;
	int x = 0;

	while (env[x] != NULL)
	{

		if (isstring(env[x], "PATH"))
		{
			path = x;
		}
		x++;
	}

	buffer = malloc(1024 * sizeof(char));
	_strcpy(env[path], buffer);

	token = strtok(buffer, "=");
	token = strtok(NULL, ":");

	x = 0;

	while (token != NULL)
	{
		exepath[x] = token;
		token = strtok(NULL, ":");
		x++;
	}
	exepath[x] = NULL;
	free(buffer);
	return (1);
}
