#include "shell.h"

/**
 * main - the main shell function, prints a prompt and interprets commands
 * creates two arrays to record received commands, firstly split by pipes
 * secondly, split by spaces. laying the groundwork for piping cmds
 * Return: always 0
 */

int main(void)
{
	int tokcnt = 0;
	int i = 0;
	int maxtok = 10;
	char *charline;
	char **environ;
	char *tokens[maxtok];
	char *cmd[maxtok];

	signal(SIGINT, handle_sigint);

	while (1)
	{
		print_prompt();
		charline = read_line();
		if (charline != NULL)
		{
			tokcnt = load_tokens(tokens, charline, maxtok, 0);
			if (tokcnt > 0)
			{
				i = 0;
				while (i < tokcnt)
				{
					load_tokens(cmd, tokens[i], maxtok, 1);
					execute_command(cmd, environ, HANDLE);
					i++;
				}
			}
		}
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
	}
	return (0);
}
