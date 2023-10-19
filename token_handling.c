#include "main.h"

/**
 * num_tokens - calculates number of tokens
 * @line_ptr: string to be tokenized
 * Return: number of tokens
*/
int num_tokens(char *line_ptr)
{
	const char *delim = " \n"; /* spaces & newline */
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
	char *delim = " \n"; /* spaces & newline */
	char *token;
	char **argv;
	int num, i;

	num = num_tokens(lineptr);
	argv = malloc(sizeof(char *) * (num + 1));
	if (argv == NULL) /* argv check */
	{
		free(lineptr_copy);
		return (NULL);
	}
	token = strtok(lineptr_copy, delim); /* tokenize */
	for (i = 0; token != NULL; i++)
	{
		argv[i] = _strcpy(token);
		if (argv[i] == NULL)
		{
			free_tokens(argv);
			free(lineptr_copy);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(lineptr_copy);
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

	if (tokens == NULL)
		return;
	/* loop to free 'argv' grid */
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	if (tokens)
		free(tokens); /* free 'argv' */
}
