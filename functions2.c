#include "main.h"

/**
 * _memcpy - Copies a  memory area.
 * @dest: The destination memory area.
 * @src: The source memory block.
 * @n: The number of bytes to be copied.
 *
 * Return: A pointer to the array dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int size = n; /* To only accept possitive integers */
	int idx = 0;

	if (size > 0)
	{
		for (; idx < size; idx++)
		{
			dest[idx] = src[idx];
		}
	}
	return (dest);
}

/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}
