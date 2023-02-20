#include <stdlib.h>
#include "shell.h"
#include <stdio.h>
/**
  * concatenate - joins two strings, using a delimeter
  * @str: points to first string
  * @string: points to second string
  * @buf: buffer to hold concatenated string
  * Return: pointer to the concatenated string
  */

char *concatenate(char *str, char *string, char *buf)
{
	int len1 = _strlen(str);
	int len2 = _strlen(string);
	int x, y;

	for (x = 0; x < len1; x++)
	{
		buf[x] = str[x];
	}

	buf[len1] = '/';

	for (y = 0; y < len2; y++)
	{
		buf[len1 + 1 + y] = string[y];
	}

	buf[len1 + len2 + 1] = '\0';

	return (buf);
}

/**
  * ispath - checks user command is a path or plain command
  * @str: command from user
  * Return: 1 if true 0 if false
  */

int ispath(char *str)
{
	if (str[0] == '/')
	{
		return (1);
	}
	return (0);
}
