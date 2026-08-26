#include "shell.h"

int print_tokens(char *str)
{
	const char delim[] = " \n";
	char *token;
	int count = 0;

	token = strtok(str, delim);

	while (token != NULL)
	{	
		count++;
		if (strcmp(token, "\0") != 0)
			printf("%s.\n", token);
		token = strtok(NULL, delim);
	}
	printf("arg count was %d\n", count);
	return (0);
}

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
	}
	return (0);
}
