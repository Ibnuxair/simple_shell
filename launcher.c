#include "shell.h"
/**
 * execCmd - executes the given command
 * @cmdPath: the command path
 * @args: the arguments
 * @env: the environment variable
 * Return: nothing
 */
void execCmd(char *cmdPath, char **args, char **env)
{
	if (execve(cmdPath, args, env) == -1)
	{
		perror(cmdPath);
		free(cmdPath);
		exit(127);
	}
}
/**
 * launch - creates a process and waits it to terminate
 * @args: the arguments to execute
 * @env: the environment variables
 * @argv: the argument vector
 * Return: always returns 1, to continue execution.
 */
int launch(char **args, char **argv, char **env)
{
	pid_t pid;
	int status, exit_status;
	char *cmd, *cmdPath;

	cmd = args[0];
	cmdPath = getPath(cmd);
	if (cmdPath == NULL || access(cmdPath, F_OK) == -1)
	{
		print_err_msg(args[0], argv[0]);
		free(cmdPath);
		exit(127);
	}

	pid = fork();
	if (pid == 0)
	{
		execCmd(cmdPath, args, env);
	}
	else if (pid < 0)
		perror("hsh");
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
			{
				free(cmdPath);
				exit(exit_status);
			}
		}
	}
	if (cmdPath != NULL && cmdPath != cmd)
		free(cmdPath);
	return (1);
}

