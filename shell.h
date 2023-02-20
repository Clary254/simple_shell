#ifndef SHELL_H
#define SHELL_H

ssize_t _getline(char *str, size_t *bufsize);
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



#endif
