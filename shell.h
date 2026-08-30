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
#define HANDLE "cool shell"

void print_prompt(void);
int load_tokens(char **tokens, char *line, int size, int phase);
char *read_line(void);
void remove_newline(char *line);
int execute_command(char **argv, char **envp, char *prog_name);
void handle_sigint(int sig);
char *get_env_value(char **envp, const char *name);
char *duplicate_string(const char *str);
char *join_path(char *dir, char *command);
char *find_command_path(char *command, char **envp);

#endif /* SHELL_H */
