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

	tokens[count] = strdup(token);
	while (token != NULL && count < size - 1)
	{
		tokens[count] = strdup(token);
		count++;
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;
	return (count);
}
