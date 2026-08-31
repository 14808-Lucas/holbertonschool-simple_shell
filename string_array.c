#include "shell.h"

/**
 * alloc_string_array - mallocs space for an array of strings
 * @size: the size of the array
 * Return: the array or NULL
 */

char **alloc_string_array(size_t size)
{
	size_t i = 0;

	char **array = malloc(size * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}
	return array;
}

/**
 * free_string_array - systematically free the memory used by the array
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */

void free_string_array(char **array, size_t size)
{
	size_t i = 0;
	
	if (!array)
		return;
	while (i < size)
	{
		/*printf("freeing: %li\n", i);*/
		free(array[i]);
		i++;
	}
	free(array);
}
