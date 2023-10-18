#include "main.h"

/**
 * execute_command - It begins the fork() process.
 * @argv: A 2D array of tokens.
 * Return: int.
 */
int execute_command(char **argv)
{
	char *cmd = NULL, *cmd_copy = NULL;
	int status = 0;

	if (argv && argv[0]) /* check for non-empty case */
	{
		/* store command */
		cmd_copy = argv[0];

		/* Check if the command is a built-in command */
		if (is_builtin_cmd(cmd_copy))
		{
			/* execute the built-in command */
			return (execute_builtin_cmd(cmd_copy, argv));
		}

		/* generate the path to the command */
		cmd = get_address(cmd_copy);
		if (cmd != NULL) /* check if PATH is valid */
		{
			/* execute the external command */
			status = execute_external_cmd(cmd, argv);
		}
		else
		{
			perror("Error");
			status = 127;
		}
	}
	return (status);
}

/**
 * is_builtin_cmd - Checks if command is a built-in (boolean).
 * @cmd_copy: The command.
 * Return: 1 if yes else 0.
 */
int is_builtin_cmd(char *cmd_copy)
{
	int (*builtin)(char **) = get_builtin(cmd_copy);

	/* boolean function */
	if (builtin != NULL)
	{
		return (1);
	}
	return (0);
}

/**
 * execute_builtin_cmd - Execute built-in command.
 * @cmd_copy: The command.
 * @argv: The command and arguments to be executed.
 * Return: xx
 */
int execute_builtin_cmd(char *cmd_copy, char **argv)
{
	int (*builtin)(char **) = get_builtin(cmd_copy);

	if (_strcmp(cmd_copy, "env") == 0)
	{
		return (builtin(environ));
	}
	else
	{
		return (builtin(argv));
	}
}

/**
 * execute_external_cmd - Executes external commands.
 * @cmd: The command.
 * @argv: The command and arguments to be executed.
 * Return: xx
 */
int execute_external_cmd(char *cmd, char **argv)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork(); /* fork a new process */
	if (child_pid == 0)
	{
		status = execute(cmd, argv);
		exit(status);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 0)
				return (0);
			else if (WEXITSTATUS(status) == 2)
				return (2);
			else if (WEXITSTATUS(status) == 127)
				return (127);
		}
		return (127);
	}
	return (status);
}

/**
 * execute - to execute the line given by user.
 * @cmd: The command to execute.
 * @argv: The command and arguments to be executed.
 * Return: void.
*/
int execute(char *cmd, char **argv)
{
	/* execute command & check execve */
	if (access(cmd, R_OK) == -1)
	{
		perror(NULL);
		exit(2);
	}
	if (execve(cmd, argv, NULL) == -1)
	{
		perror("Error");
		return (2);
	}
	return (0);
}
