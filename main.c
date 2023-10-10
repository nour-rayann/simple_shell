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
		char *line_ptr = NULL;
		char **tokens;
		int state;
		(void)ac;
		(void)argv;

	while (1)
	{

		printf("simple_shell$ ");
		num_char_read = getline(&line_ptr, &n, stdin);
		if (num_char_read == -1)
		{
			free(line_ptr);
			exit(0);
		}

		tokens = create_tokens(line_ptr);

		execute_command(tokens);
		free_tokens(tokens);
		wait(&state);
	}
	free(line_ptr);
	return (0);
}