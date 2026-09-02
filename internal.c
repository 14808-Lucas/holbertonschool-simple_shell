#include "shell.h"

/**
 * internal - checks if a command and args can be handled
 * @array: the array of strings containing a command and args
 * Return: 1 if command was handled, 0 if not handled
 */

int internal(char **array)
{
	if (strcmp(array[0], "exit") == 0)
		return (1);
	if (strcmp(arrary[0], "env") == 0)
		return (2);
	return (0);
}
