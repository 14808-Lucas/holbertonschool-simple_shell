#include "shell.h"
/**
 * print_env - prints the current environment, one variable per line
 * @envp: the environment array to print
 */
void print_env(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	fflush(stdout);
}
