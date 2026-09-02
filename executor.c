#include "shell.h"

/**
 * execute_command - forks a child process and executes a
 * command with execve, resolving it through PATH first.
 * @argv: the command to run including arguments, already tokenized
 * @envp: environment variables to pass through to the new program
 * @prog_name: the name the shell itself was invoked with (argv[0]),
 * used to prefix error messages exactly like /bin/sh does
 * @line_num: the line that was read and passed to this function
 * used in error message to assist debugging
 *
 * Return: the exit status of the child process, 127 if the command could
 * not be resolved via PATH,  or 1 if fork failed
 */
int execute_command(char **argv, char **envp, char *prog_name, int line_num)
{
	pid_t child_pid;
	int status;
	char *full_path;

	full_path = find_command_path(argv[0], envp);
	if (full_path == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
			prog_name, line_num,  argv[0]);
		return (127);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(prog_name);
		free(full_path);
		return (1);
	}

	if (child_pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(full_path, argv, envp) == -1)
		{
			perror(prog_name);
			_exit(127);
		}
	}
	else
	{
		wait(&status);
		free(full_path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}
