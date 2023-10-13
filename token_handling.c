#include "main.h"

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
	while (token) /* tokenize command & arguments */
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
	argv = malloc(sizeof(char *) * num); /* malloc for tokens */
	token = strtok(lineptr, delim);

	for (i = 0; token != NULL; i++)
	{
		/* create grid to store tokens */
		argv[i] = malloc(_strlen(token) * sizeof(char));
		argv[i] = _strcpy(token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL; /* terminate with NULL byte */

	return (argv);
}

/**
 * free_tokens - Free 2D array of tokens.
 * @tokens: A 2D array.
 * Return: Void.
 */
void free_tokens(char **tokens)
{
	int i;

	/* loop to free 'argv' grid */
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens); /* free 'argv' */
}
