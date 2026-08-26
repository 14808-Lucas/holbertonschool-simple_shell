#include "shell.h"

/**
 * read_line - reads one line of input from stdin using getline
 *
 * Return: a malloc'd string containing the line read (including any
 * trailing newline), or NULL if EOF was reached or an error occurred
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * remove_newline - replaces the first newline character in a string
 * with a null byte, effectively trimming it
 * @line: the string to modify in place
 */
void remove_newline(char *line)
{
	char *newline_position;

	newline_position = strchr(line, '\n');
	if (newline_position != NULL)
		*newline_position = '\0';
}
