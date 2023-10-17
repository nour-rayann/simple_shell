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
	if (copied == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		copied[i] = line_ptr[i];
	}
	copied[i] = '\0';
	return (copied);
}

/**
 * _strcpy2 - Copies a string pointed to by @src, including
 *           the terminating null byte, to a buffer pointed
 *           to by @dest.
 * @dest: A buffer to copy the string to.
 * @src: The source string to copy.
 *
 * Return: A pointer to the @dest.
 */

char *_strcpy2(char *dest, char *src)
{
	int idx;
	int len = 0;

	/** A loop to find the length of the string */
	while (src[len] != '\0')
	{
		len++;
	}

	for (idx = 0; idx <= len; idx++)
	{
		dest[idx] = src[idx];
	}
	return (dest);
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
 * _strcat - appends the src string to the dest string,
 *           overwriting the terminating null byte (\0)
 *           at the end of dest, and then adds a
 *           terminating null byte.
 *
 * @src: The source string.
 * @dest: The destination string.
 * Return: a pointer to the resulting string dest.
 */

char *_strcat(char *dest, char *src)
{
	int didx = 0;
	int sidx = 0;

	/* A loop to put pointer at string end */
	while (dest[didx] != '\0')
	{
		didx++;
	}

	while (src[sidx] != '\0')
	{
		dest[didx] = src[sidx];
		didx++;
		sidx++;
	}
	dest[didx] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 *
 * Return: int that tells num spaces in between
 */

int _strcmp(char *s1, char *s2)
{
	/* Make sure not at end of string */
	while ((*s1 != '\0') || (*s2 != '\0'))
	{
		/* if elements a different, return the difference */
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		/* loop index */
		s1++;
		s2++;
	}
	return (0);
}
