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
#define BUFFER_SIZE 1024

extern char **environ;

/*prototypes*/
int exec(char **args, char **argv, char **env);
char *removeNewLine(char *line);
char *readLine(void);
char **splitLine(char *line);
size_t _strlen(const char *s);
void loop(char **argv, char **env);
int launch(char **args, char **argv, char **env);
void print_err_msg(char *arg, char *argv);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *getPath(char *cmd);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
int hsh_print_env(char **args);
int hsh_exit(char **args);
char *__findenv(const char *name, int *offset);
char *_getenv(const char *name);
/*const char *_strchr(const char *s, char c);*/
/*char *_strtok(char *line, const char *delim);*/
void exec_bin_ls(char **env);

#endif
