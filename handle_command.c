#include "shell.h"

/**
 * handle_command - decides whether a tokenized command is a built-in
 * or should be executed externally, and acts on it
 * @cmd: the tokenized command and its arguments
 * @tokens: the outer token array, needed only if exit is triggered
 * @n: the size of both arrays, needed for clean_exit
 * @prog_name: the shell's own name, for error messages
 * @line_num: the current line number, for error messages
 * @status: pointer to the shell's exit status, updated on execution
 */

void handle_command(char **cmd, char **tokens, size_t n,
	char *prog_name, int line_num, int *status, char *charline)
{
	int me;

	me = internal(cmd);
	if (me == 0)
		*status = execute_command(cmd, environ, prog_name, line_num);
	else if (me == 1)
		clean_exit(tokens, cmd, charline, n, *status);
}
