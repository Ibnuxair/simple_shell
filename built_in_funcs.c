#include "shell.h"

/**
 * is_valid_exit_status - checks if exit status is valid
 * @str: string to check
 * Return: 1 if it is valid otherwise 0
 */
int is_valid_exit_status(char *str)
{
	int i, status;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	status = _atoi(str);
	if (status >= 0 && status <= 255)
		return (1);

	return (0);
}
/**
 * hsh_exit - exits the shell
 * @args: the arguments
 *
 * Return: nothing
 */

int hsh_exit(char **args)
{
	int i,  stat;
	const char *error_message = "./hsh: 1: exit: Illegal number: ";

	if (args[1] != NULL)
	{
		if (is_valid_exit_status(args[1]))
		{
			stat = _atoi(args[1]);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			exit(stat);
		}
		else
		{
			write(STDERR_FILENO, error_message,
			      _strlen(error_message));
			write(STDERR_FILENO, args[1], _strlen(args[1]));
			write(STDERR_FILENO, "\n", 1);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			exit(2);
		}
	}
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	exit(0);
}
/**
 * hsh_print_env -  prints the current environment
 * @args: the arguments
 *
 * Return: 1
 */
int hsh_print_env(char __attribute__((unused))**args)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env++);

	}
	return (1);
}
