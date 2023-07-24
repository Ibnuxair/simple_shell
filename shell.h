#ifndef SHELL_H
#define SHELL_H

/*headers*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <stddef.h>

/*macros*/
#define DELIM " \t\r\n\a"

extern char **environ;

/*prototypes*/
int exec(char **args, char **argv, char **env);
char *removeNewLine(char *line);
char *readLine(void);
size_t _strlen(const char *s);
void loop(char **argv, char **env);
int launch(char **args, char **argv, char **env);
void print_err_msg(char *arg, char *argv);
char *_strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
char *getPath(char *cmd);
int _strcmp(const char *s1, const char *s2);
int _atoi(char *s);
int hsh_print_env(char **args);
int hsh_exit(char **args);
char *_getenv(const char *name);

#endif
