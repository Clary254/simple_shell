#include <stdlib.h>
#include <stdio.h>


/**
  * _strcpy - copies string from src to dest
  * @src: string to be copied
  * @dest: string to be filled with content of src
  * Return: pointer to dest
  */

char *_strcpy(char *src, char *dest)
{
	int x = 0;

	while (*src != '\0')
	{
		dest[x] = src[0];
		src++;
		x++;
	}

	dest[x++] = '\0';

	return (dest);
}

/**
  * _isspace - checks if character is a space or not
  * @c: character to check
  * Return: 1 if c is a space otherwise 0
  */

int _isspace(int c)
{
	if (c == 32)
		return (1);

	return (0);
}
/**
  * parse_command - parses command
  * @command: input from user
  * @path: parsed from the @command
  * Return: pointer to @path
  */

char *parse_command(char *command, char *path)
{
	int x = 0;
	char c;

	while (c != '\0')
	{
		if (c == '\0' || _isspace(c))
		{
			break;
		}
		path[x] = command[x];
		x++;
		c = command[x];
	}

	path[x] = '\0';
	return (path);
}

/**
  * _strlen - calculates length of a string
  * @str: string to calculate length
  * Return: length of the string
  */

int _strlen(char *str)
{
	int len = 0;
	char c;

	if (str == NULL)
	{
		return (0);
	}
	c = str[len];

	while (c != '\0')
	{
		len++;
		c = str[len];
	}

	return (len);
}

/**
  * isstring - finds occurence of substring in a string
  * @str: points to string to search in
  * @substr: points to string being searched for
  * Return: 1 if substring found otherwise return 0
  */

int isstring(char *str, char *substr)
{
	int x = 0, y = 0;
	char c;

	if (str == NULL || substr == NULL)
	{
		return (0);
	}
	c = str[x];

	while (c != '\0')
	{
		if (c == substr[y])
		{
			y++;

			if ((y + 1) == _strlen(substr))
			{
				return (1);
			}
		} else
		{
			y = 0;
		}
		x++;
		c = str[x];
	}

	return (0);
}
