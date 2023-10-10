#include "main.h"

/**
 * _strcpy - copies a string into another
 * @line_ptr: to be copied
 * Return: pointer to the copied string
*/
char *_strcpy(char *line_ptr)
{
	char *copied = NULL;
	int i, len;

	len = _strlen(line_ptr);
	copied = malloc((len + 1) * sizeof(char));
	for (i = 0; i <= len; i++)
	{
		copied[i] = line_ptr[i];
	}
	return (copied);
}

/**
 * _strlen - calculates length of a string
 * @str: to calculate its length
 * Return: length of string
*/
int _strlen(char *str)
{
	int len = 0;

	for (; str[len] != '\0'; len++)
	;
	return (len);
}

/**
 * num_tokens - calculates number of tokens
 * @line_ptr: string to be tokenized
 * Return: number of tokens
*/
int num_tokens(char *line_ptr)
{
	const char *delim = " \n";
	char *token;
	int num = 1;

	token = strtok(line_ptr, delim);
	while (token)
	{
		num++;
		token = strtok(NULL, delim);
	}
	return (num);
}

/**
 * create_tokens - It handle tokenization.
 * @lineptr: String passed to the shell.
 * Return: argv a 2D array.
 */
char **create_tokens(char *lineptr)
{
	char *lineptr_copy = _strcpy(lineptr);
	char *delim = " \n";
	char *token;
	char **argv;
	int num, i;

	num = num_tokens(lineptr_copy);
	argv = malloc(sizeof(char *) * num);
	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(_strlen(token) * sizeof(char));
		argv[i] = _strcpy(token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * execute_command - It begins the fork() process.
 * @argv: A 2D array of tokens.
 * Return: void.
 */
void execute_command(char **argv)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execute(argv);
		exit(0);
	}
}
