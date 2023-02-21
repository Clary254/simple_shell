#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFSIZE 1024
/**
  * setpath - sets the fullpath to the executable
  * @command: input from the user
  * @path: pointer to string to hold full path
  * @env: environment variables
  * Return: 1 on success otherwise 0
  */

int setpath(char *command, char *path, char **env)
{
	char **exe;
	char *newpath;
	struct stat file;
	int x = 0;

	if (!ispath(command))
	{
		exe = malloc(BUFSIZE * sizeof(char *));
		get_exe_path(exe, env);

		while (exe[x] != NULL)
		{
			newpath = malloc(1024 * sizeof(char));
			if (newpath == NULL)
			{
				return (0);
			}

			concatenate(exe[x], command, newpath);

			if (stat(newpath, &file) == 0)
			{
				_strcpy(newpath, path);
				free(newpath);
				free(exe);
				return (1);
			}
			free(newpath);
			x++;
		}

	} else
	{
		_strcpy(command, path);
	}

	return (1);
}


/**
  * execute_program - forks process and executes given program
  * @path: path to program
  * @args: commands to be passed to program
  * @env: environment variables
  * Return: 1 for success
  */

int execute_program(char *path, char **args, char **env)
{

	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("Fork");
	} else if (pid == 0)
	{
		execve(path, args, env);
		perror("./shell");
	} else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}

/**
  * main_loop - carries the main functions of the shell
  * @env: environment variables
  * Return: void
  */

void main_loop(char **env)
{
	char command[BUFSIZE];
	char *path;
	char *newpath;
	char *args[BUFSIZE];
	size_t bufsize = BUFSIZE;
	ssize_t command_len;
	int status;
	builtin_function b_func;

	do {
		printf("> ");
		command_len = _getline(command, &bufsize);
		command[command_len - 1] = '\0';
		path = malloc(BUFSIZE * sizeof(char));
		newpath = malloc(BUFSIZE * sizeof(char));

		if (path == NULL || newpath == NULL)
		{
			perror("malloc");

		}

		parse_command(command, path);
		setargs(args, command);
		b_func = get_builtin_func(path);

		if (b_func != NULL)
		{
			status = b_func(env, args);
		} else
		{
			setpath(path, newpath, env);
			status = execute_program(newpath, args, env);
			free(path);
			free(newpath);
		}
	} while (status);
}







