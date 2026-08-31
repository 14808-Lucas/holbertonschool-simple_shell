#include "shell.h"
#define MAXTOK 10

/**
 * main - the main shell function, prints a prompt and interprets commands
 * creates two arrays to record received commands, firstly split by pipes
 * secondly, split by spaces. laying the groundwork for piping cmds
 * Return: always 0
 */

int main(int argc, char **argv)
{
	int tokcnt = 0;
	int i = 0;
	int is_eof;
	int status = 0;
	char *charline;
	char *tokens[MAXTOK];
	char *cmd[MAXTOK];

	(void)argc;
	signal(SIGINT, handle_sigint);
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_prompt();
		charline = read_line(&is_eof);
		if (charline != NULL)
		{
			tokcnt = load_tokens(tokens, charline, MAXTOK, 0);
			if (tokcnt > 0)
			{
				i = 0;
				while (i < tokcnt)
				{
					load_tokens(cmd, tokens[i], MAXTOK, 1);
					status = execute_command(cmd, environ, argv[0]);
					i++;
				}
			}
			free(charline);
		}
		else
		{
			if (is_eof)
			{
				if (isatty(STDIN_FILENO))
					printf("\n");
				exit(0);
			}
		}
	}
	return (status);
}
