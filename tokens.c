#include "shell.h"

/**
 * load_tokens - received a pointer to a string array, a string and a size
 * splits string into tokens and stores each in the array
 * @tokens: the array
 * @line: the input line string
 * @size: the size of the array
 * @phase: determines which delim to use, space or pipe
 * Return: the number of tokens found
 */

int load_tokens(char **tokens, char *line, int size, int phase)
{
	char *token;
	int count = 0;
	char delim[] = "|\n";

	if (phase != 0)
		delim[0] = ' ';

	token = strtok(line, delim);
	if (token == NULL)
		return (0);

	tokens[count] = token;
	while (token != NULL && count < size)
	{
		count++;
		if (strcmp(token, "\0") != 0)
		{
			token = strtok(NULL, delim);
			tokens[count] = token;
		}
	}
	tokens[count + 1] = NULL;
	return (count);
}
