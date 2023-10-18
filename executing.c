#include "main.h"

/**
 * execute_command - It begins the fork() process.
 * @argv: A 2D array of tokens.
 * Return: int.
 */
int execute_command(char **argv)
{
	pid_t child_pid;
	char *cmd = NULL, *cmd_copy = NULL;
	int status = 0;
	int (*builtin)(char **);

	if (argv && argv[0]) /* check for non-empty case */
	{
		/* store command */
		cmd_copy = argv[0];

		/* Check if the command is a built-in command */
		builtin = get_builtin(cmd_copy);

		if (builtin != NULL)
		{
			/* Execute the built-in command */
			if (_strcmp(cmd_copy, "env") == 0)
			{
				return (builtin(environ));
			}
			else
			{
				return (builtin(argv));
			}
		}

		/* generate the path to the command */
		cmd = get_address(cmd_copy);
		if (cmd != NULL) /* check if PATH is valid */
		{
			child_pid = fork(); /* fork a new process */
			if (child_pid == 0)
			{
				status = execute(cmd, argv);
				free(cmd);
				cmd = NULL;
				exit(status);
			}
			else
			{
				waitpid(child_pid, &status, 0);
				if (WIFEXITED(status))
				{
					status = WEXITSTATUS(status);
				}
			}
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
 * execute - to execute the line given by user.
 * @cmd: The command to execute.
 * @argv: command and arguments to be executed.
 * Return: void.
*/
int execute(char *cmd, char **argv)
{
	/* execute command & check execve */
	if (execve(cmd, argv, NULL) == -1)
	{
		perror("Error");
		return (2);
	}
	return (0);
}
