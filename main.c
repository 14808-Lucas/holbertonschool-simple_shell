#include "shell.h"

/**
 * main - the main shell function, prints a prompt and interprets commands
 * Return: always 0
 */

int main()
{
	int tokcnt = 0;
	int i = 0;
	int maxtok = 10;
	int state = 0;
	char *charline;
	extern char **environ;
	char *tokens[maxtok];

	while (state == 0)
	{
		printf(PROMPT);
		charline = read_line();
		if (charline != NULL)
		{
			tokcnt = load_tokens(tokens, charline, maxtok);
			if (tokcnt > 0)
			{	
				i = 0;
				while (i < tokcnt)
				{
					execute_command(tokens[i], environ, "thishell" );
					i++;
				}
			}
		}
		if (feof(stdin))
			state = 1;
	}
	return (0);
}
