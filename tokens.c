#include "shell.h"

/**
 * load_tokens - received a pointer to a string array, a string and a size
 * splits string into tokens and stores each in the array
 * @tokens: the array
 * @line: the input line string
 * @size: the size of the array
 * Return: the number of tokens found
 */

int load_tokens(char **tokens, char *line, int size)
{
	const char delim[] = " \n";
	char *token;
	int count = 0;

	token = strtok(line, delim);
	if (token != NULL)
		tokens[count] = token;
	else
	{
		/*printf("no tokens received\n");*/
		return (0);
	}
	while (token != NULL && count < size)
	{
		count++;
		if (strcmp(token, "\0") != 0)
		{
			token = strtok(NULL, delim);
			tokens[count] = token;
		}
	}
	/*printf("token count was %d\n", count);*/
        return (count);
}
