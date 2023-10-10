#include "main.h"
/**
 * main - main function for shell
 * @ac: number of arguments
 * @argv: list of arguments
 * Return: int
*/
int main(int ac, char **argv)
{
		ssize_t num_char_read;
		size_t n;
		char *line_ptr = NULL, *line_copy = NULL;
		char *delim = " \n", *token;
		int num, i, state;
		(void)ac;

	while (1)
	{
		pid_t child_pid;

		printf("simple_shell$ ");
		num_char_read = getline(&line_ptr, &n, stdin);
		if (num_char_read == -1)
		{
			free(line_ptr);
			exit(0);
		}
		line_copy = _strcpy(line_ptr);
		if (line_copy)
		{
			num = num_tokens(line_ptr);
			argv = malloc(sizeof(char *) * num);
			token = strtok(line_copy, delim);
			for (i = 0; token != NULL; i++)
			{
				argv[i] = malloc(_strlen(token) * sizeof(char));
				argv[i] = _strcpy(token);
				token = strtok(NULL, delim);
			}
			argv[i] = NULL;
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			execute(argv);
			exit(0);
		}
		wait(&state);
		free(argv);
	}
	free(line_copy);
	free(line_ptr);
	return (0);
}
