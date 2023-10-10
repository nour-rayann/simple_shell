#include "main.h"
/**
 * execute - to execute the line given by user
 * @argv: command to be executed
 * Return: nothing
*/
void execute(char **argv)
{
	if (argv)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
