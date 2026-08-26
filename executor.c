#include "shell.h"

/**
 * execute_command - forks a child process and executes a single-word
 * command with execve
 * @command: the command to run (may be a relative or absolute path,
 * since this version does not search PATH)
 * @envp: environment variables to pass through to the new program
 * @prog_name: the name the shell itself was invoked with (argv[0]),
 * used to prefix error messages exactly like /bin/sh does
 *
 * Return: the exit status of the child process, or 1 if fork failed
 */
int execute_command(char *command, char **envp, char *prog_name)
{
	pid_t child_pid;
	int status;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(prog_name);
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror(prog_name);
			_exit(127);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}
