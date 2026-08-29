#include "shell.h"

/**
 * execute_command - forks a child process and executes a single-word
 * command with execve
 * @argv: the command to run including arguments (must be absolute
 * since this version does not search PATH)
 * @envp: environment variables to pass through to the new program
 * @prog_name: the name the shell itself was invoked with (argv[0]),
 * used to prefix error messages exactly like /bin/sh does
 *
 * Return: the exit status of the child process, or 1 if fork failed
 */
int execute_command(char **argv, char **envp, char *prog_name)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(prog_name);
		return (1);
	}

	if (child_pid == 0)
	{
		signal(SIGINT, SIG_DFL);
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
