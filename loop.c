#include "shell.h"

/**
 * loop - executes the main loop
 * @argv: argument vector
 * @env: environment variable
 */

void loop(char **argv, char **env)
{
	int i, from_pipe = !isatty(STDIN_FILENO);
	char *line, **args;
	size_t status;

	do {
		if (!from_pipe)
		{
			/*interactive mode*/
			write(STDOUT_FILENO, "($) ", 4);
		}
		line = readLine();
		args = splitLine(line);
		if (!args)
			continue;
		status = exec(args, argv, env);

		/*free(line);*/
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
		/*args = NULL;*/
		if (status == 2)
		{
			break;
		}
	} while (status);
}
