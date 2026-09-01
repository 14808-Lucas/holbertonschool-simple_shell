#include "shell.h"

/**
 * clean_exit - function to correctly free memory, and print new line
 * before exiting program
 * @array1: the first array to free
 * @array2: the 2nd array to free
 * @n: the size of the arrays
 * Return: always void
 */

void clean_exit(char **array1, char **array2, size_t n)
{
	if (isatty(STDIN_FILENO))
		printf("\n");
	free_string_array(array1, n);
	free_string_array(array2, n);
	exit(0);
}
