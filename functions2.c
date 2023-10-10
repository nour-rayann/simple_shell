#include "main.h"

/**
 * free_tokens - Free 2D array of tokens.
 * @tokens: A 2D array.
 * Return: Void.
 */
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
