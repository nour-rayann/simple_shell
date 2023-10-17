#include "main.h"
/**
 * main - main function for shell
 * Return: int
*/
int main(void)
{
	ssize_t num_char_read;
	size_t n;
	char *line_ptr = NULL;
	char **tokens;
	int state;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("simple_shell$ ");
		num_char_read = getline(&line_ptr, &n, stdin);
		if (num_char_read == -1)
		{
			if (line_ptr)
				free(line_ptr);
			exit(0);
		}
		tokens = create_tokens(line_ptr);
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free_tokens(tokens);
			free(line_ptr);
			line_ptr = NULL;
			exit(0);
		}
		execute_command(tokens);
		free_tokens(tokens);
		wait(&state);
	}
	free(line_ptr);
	return (state);
}
