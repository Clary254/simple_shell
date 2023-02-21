#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stddef.h>

typedef int (*builtin_function)(char **env, char **args);

/**
  * struct builtin - structure for builtin_function and its identifier
  * @name: identifier for function
  * @b_function: function
  */
typedef struct builtin
{
	char *name;
	builtin_function b_function;
} struct_builtin;


size_t _getline(char *str, size_t *bufsize);
char **setargs(char **tokens, char *str);
char *_strcpy(char *src, char *dest);
void main_loop(char **env);
int _isspace(int c);
char *parse_command(char *command, char *path);
size_t _strlen(char *str);
int isstring(char *str, char *substr);
int get_exe_path(char **exepath, char **env);
char *concatenate(char *str, char *string, char *buf);
int setpath(char *command, char *path, char **env);
int ispath(char *str);
int _exit_shell(char **env, char **args);
int print_env(char **env, char **args);
builtin_function get_builtin_func(char *fname);

#endif
