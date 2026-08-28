#include "shell.h"

/**
 * handle_sigint - handles Ctrl+C (SIGINT) while the shell is waiting
 * for input; lets the interrupted read resume instead of exiting
 * @sig: the signal number (unused, required by the handler signature)
 */
void handle_sigint(int sig)
{
	(void)sig;

	write(STDOUT_FILENO, "\n", 1);
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}
