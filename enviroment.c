#include "main.h"

/**
 * cmp_env_name - compares env variables names to name passed.
 * @nenv: name of the environment variable.
 * @name: name passed.
 * Return: 0 if no match, else index to ('=' + 1).
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int idx;

	for (idx = 0; nenv[idx] != '='; idx++)
	{
		if (nenv[idx] != name[idx]) /* not a match */
		{
			return (0);
		}
	}

	return (idx + 1); /* ('=' + 1) */
}

/**
 * _getenv - Gets an environment variable.
 * @name: name of the environment variable.
 * Return: value of the environment variable if is found,
 *         else, returns NULL.
 */
char *_getenv(const char *name)
{
	char *env_val;
	int idx, mov;

	env_val = NULL;
	mov = 0; /* used to store int value of index of ('=' + 1) */

	/* Compare all environment variables */
	/* environ is declared in the "main.h" */
	for (idx = 0; environ[idx]; idx++)
	{
		/* check for match and store index of ('=' + 1) */
		mov = cmp_env_name(environ[idx], name);
		if (mov)
		{
			/* store value from ('=' + 1) of environ[idx] */
			env_val = environ[idx];
			break;
		}
	}

	if (mov == 0 || environ[idx] == NULL) /* check mov & match */
	{
		return (NULL);
	}

	return (env_val + mov);
}

/**
 * _env - prints the evironment variables.
 * @environ: environmental variables
 * Return: 1 for success.
 */
int _env(char **environ)
{
	int i;
	ssize_t bytes_written;

	for (i = 0; environ[i]; i++)
	{
		bytes_written = write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		if (bytes_written == -1 || bytes_written != _strlen(environ[i]))
		{
			fprintf(stderr, "Failed to write environment variable\n");
			return (-1);
		}

		bytes_written = write(STDOUT_FILENO, "\n", 1);
		if (bytes_written == -1 || bytes_written != 1)
		{
			fprintf(stderr, "Failed to write newline\n");
			return (-1);
		}
	}

	return (1);
}
