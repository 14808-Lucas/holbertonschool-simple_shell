#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>

#define PROMPT "$$$ "
#define HANDLE "cool shell"

extern char **environ;

int internal(char **array);
char **alloc_string_array(size_t size);
void free_string_array(char **array, size_t size);
void print_prompt(void);
int load_tokens(char **tokens, char *line, int size, int phase);
char *read_line(int *is_eof);
void remove_newline(char *line);
int execute_command(char **argv, char **envp, char *prog_name, int line_num);
void handle_sigint(int sig);
char *get_env_value(char **envp, const char *name);
char *duplicate_string(const char *str);
char *join_path(char *dir, char *command);
char *find_command_path(char *command, char **envp);
void clean_exit(char **array1, char **array2, size_t n);
void handle_command(char **cmd, char **tokens, size_t n,
	char *prog_name, int line_num, int *status);

#endif /* SHELL_H */
