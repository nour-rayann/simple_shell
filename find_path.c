#include "main.h"

/**
 * get_address - Gets the aaddress of the command.
 * @cmd_copy: A sting containing the command.
 * Return: The path to the command.
 */

char *get_address(char *cmd_copy)
{
	char *path, *path_copy, *path_token, *file_path;

	path = getenv("PATH");

	if (path)
	{
		path_copy = _strdup(path); /* duplicate path */
		path_token = strtok(path_copy, ":"); /* tokenize path */

		while (path_token != NULL)
		{
			file_path = check_dir(path_token, cmd_copy, _strlen(cmd_copy));
			if (file_path != NULL) /* check if path is valid */
			{
				free(path_copy); /* free _strdup malloc */
				return (file_path);
			}

			path_token = strtok(NULL, ":"); /* tokenize path */
		}
		free(path_copy);
		/* check if cmd is a path */
		file_path = check_cmd(cmd_copy);
		return (file_path);
	}
	return (NULL);
}

/**
 * check_dir - Checks each directory for the command, and then
 *             Builds the path for command.
 * @path_token: Tokenize path.
 * @cmd_copy: A coppy of the command.
 * @cmd_length: The length of the command string.
 * Return: A pointer to a string that is the file path.
 */

char *check_dir(char *path_token, char *cmd_copy, int cmd_length)
{
	char *file_path;
	struct stat buffer;
	int dir_length;

	dir_length = _strlen(path_token);
	file_path = malloc(cmd_length + dir_length + 2); /* +2 is for '/' & '\0' */
	if (file_path == NULL)
		return (NULL);
	/* build path for command: */
	_strcpy2(file_path, path_token); /* 1. copy directory path */
	_strcat(file_path, "/"); /* 2. add slash to path */
	_strcat(file_path, cmd_copy); /* 3. add command to path */
	_strcat(file_path, "\0"); /* 4. add NULL byte to end of string */

	if (stat(file_path, &buffer) == 0) /* validate file_path */
	{
		return (file_path);
	}
	else
	{
		free(file_path);
		file_path = NULL;
		return (NULL);
	}
}

/**
 * check_cmd - Checks if the command is a file path itself.
 * @cmd_copy: The command.
 * Return: A pointer to the command.
 */

char *check_cmd(char *cmd_copy)
{
	struct stat buffer;

	if (stat(cmd_copy, &buffer) == 0) /* validate command/path */
	{
		return (cmd_copy);
	}
	return (NULL);
}
