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

/**
 * trim_spaces - Removes leading and trailing whitespace from a string.
 * @cmd: The string to be trimmed.
 * Return: A pointer to the trimmed string.
 */
char *trim_spaces(char *cmd)
{
	int i = 0, n;

	/**Remove leading spaces*/
	while (isspace(cmd[i]))
		i++;
	n = _strlen(cmd + i);
	if (n == 0)
	{
		cmd = NULL;
		return (cmd);
	}
	/**Remove trailing spaces*/
	while (isspace(cmd[i + n - 1]))
		n--;
	cmd[i + n] = '\0';
	return (cmd);
}
