#include "shell.h"
#include <limits.h>

/**
 * print_prompt - get the current working directory and print it with a prompt
 */

void print_prompt(void)
{
	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s%s", cwd, PROMPT);
	else
	{
		perror("getcwd");
		printf("%s", PROMPT);
	}
	fflush(stdout);
}
