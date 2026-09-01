#include "shell.h"

/**
 * main - the main shell function, prints a prompt and interprets commands
 * creates two arrays to record received commands, firstly split by pipes
 * secondly, split by spaces. laying the groundwork for piping cmds
 * @argc: argument count
 * @argv: argument vector
 * Return: always 0
 */

int main(int argc, char **argv)
{
	int i, me, is_eof, cmd_argc, status, tokcnt;
	size_t n = 6;
	char *charline;
	char **tokens = alloc_string_array(n);
	char **cmd = alloc_string_array(n);

	(void)argc;
	signal(SIGINT, handle_sigint);
	tokcnt = status = 0;
	while (1)
	{
		print_prompt();
		charline = read_line(&is_eof);
		if (charline != NULL)
		{
			tokcnt = load_tokens(tokens, charline, n, 0);
			if (tokcnt > 0)
			{
				i = 0;
				while (i < tokcnt)
				{
					cmd_argc = load_tokens(cmd, tokens[i], n, 1);
					if (cmd_argc > 0)
					{
						me = internal(cmd);
						if (me == 0)
							status = execute_command(cmd, environ, argv[0]);
						if (me == 1)
							clean_exit(tokens, cmd, n);
					}
					i++;
				}
			}
			free(charline);
		}
		if (is_eof)
			clean_exit(tokens, cmd, n);
	}
	return (status);
}
