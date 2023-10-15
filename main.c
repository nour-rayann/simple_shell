#include "main.h"
/**
 * main - main function for shell
 * Return: int
*/
int main(void)
{
	struct stat stdin_stat;
	ssize_t num_char_read;
	size_t n;
	char *line_ptr = NULL;
	char **tokens;
	int state;

	while (1)
	{
		if (fstat(STDIN_FILENO, &stdin_stat) == 0 && S_ISCHR(stdin_stat.st_mode))
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
