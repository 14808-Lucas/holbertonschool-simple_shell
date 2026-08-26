#include "shell.h"

int main()
{
	char *charline;
	
	printf(PROMPT);

	charline = read_line();
	
	if (charline != NULL)
	{
		printf("Input was: %s", charline);
	}
	return (0);
}
