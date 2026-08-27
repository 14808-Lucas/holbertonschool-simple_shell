#include "shell.h"

/**
 * main - the main shell function, prints a prompt and interprets commands
 * Return: always 0
 */

int main()
{
	int state = 0;
	char *charline;
	
	while (state == 0)
	{
		printf(PROMPT);
		charline = read_line();
		if (charline != NULL)
		{
			print_tokens(charline);	
		}
		if (feof(stdin))
			state = 1;
	}
	return (0);
}
