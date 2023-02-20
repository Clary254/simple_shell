#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <string.h>
/**
  * main - entry point of the program
  * @ac: count of argumnets passed in
  * @av: array of arguments paased in
  * @env: array of environment variables
  * Return: always 0 (success);
  */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	main_loop(env);
	return (0);
}
