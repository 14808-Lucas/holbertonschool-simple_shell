#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define PROMPT "$$$ "

int print_tokens(char *str);
char *read_line(void);
void remove_newline(char *line);
int execute_command(char *command, char **envp, char *prog_name);
void handle_sigint(int sig);

#endif /* SHELL_H */
