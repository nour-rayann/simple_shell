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
