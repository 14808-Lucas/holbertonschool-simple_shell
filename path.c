#include "shell.h"

/**
 * get_env_value - finds the value of an environment variable
 * @envp: the environment array to search
 * @name: the variable name to look for, e.g. "PATH"
 *
 * Return: a pointer to the value (inside envp's own memory), or NULL
 * if the variable isn't set
 */
char *get_env_value(char **envp, const char *name)
{
	size_t name_len;
	int i;

	name_len = strlen(name);
	i = 0;
	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], name, name_len) == 0 && envp[i][name_len] == '=')
			return (envp[i] + name_len + 1);
		i++;
	}
	return (NULL);
}

/**
 * join_path - builds a "dir/command" style path
 * @dir: the directory
 * @command: the command name
 *
 * Return: a malloc'd string "dir/command", or NULL if allocation failed
 */
char *join_path(char *dir, char *command)
{
	char *full_path;

	full_path = malloc(strlen(dir) + strlen(command) + 2);
	if (full_path == NULL)
		return (NULL);
	sprintf(full_path, "%s/%s", dir, command);
	return (full_path);
}

/**
 * find_command_path - resolves a command name to a full, executable path
 * @command: the command as typed by the user
 * @envp: environment variables, used to look up PATH
 *
 * Return: a malloc'd string containing the full path, or NULL if the
 * command could not be resolved
 */
char *find_command_path(char *command, char **envp)
{
	char *path_value;
	char *path_copy;
	char *dir;
	char *full_path;

	if (strchr(command, '/') != NULL)
		return (strdup(command));

	path_value = get_env_value(envp, "PATH");
	if (path_value == NULL)
		return (NULL);

	path_copy = strdup(path_value);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = join_path(dir, command);
		if (full_path != NULL && access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
