#include "shell.h"

/**
 * print_tokens - splits a string into tokens and prints each on a line
 * helper function to understand strtok
 * @str: pointer to the string
 * Return: always 0
 */

int print_tokens(char *str)
{
        const char delim[] = " \n";
        char *token;
        int count = 0;

        token = strtok(str, delim);

        while (token != NULL)
        {
                count++;
                if (strcmp(token, "\0") != 0)
                        printf("%s\n", token);
                token = strtok(NULL, delim);
        }
        printf("arg count was %d\n", count);
        return (0);
}
