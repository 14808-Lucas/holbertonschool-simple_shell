#include "shell.h"

/**
 * main - the main shell function, prints a prompt and interprets commands
 * Return: always 0
 */

int main()
{
	int state = 0;
	char *charline;
	
	char *ENV = getenv("PATH");
	extern char **environ;

	/*printf("PATH = %s\n", ENV);*/

	while (state == 0)
	{
		printf(PROMPT);
		charline = read_line();
		if (charline != NULL)
		{
			/*print_tokens(charline);*/
			execute_command("/bin/ls", environ, "thishell" );
		}
		if (feof(stdin))
			state = 1;
	}
	return (0);
}
