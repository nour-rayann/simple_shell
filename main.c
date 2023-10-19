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
	int state, loop_count = 0;

	while (1)
	{
		loop_count++;
		if (isatty(STDIN_FILENO))
			printf("$ ");

		num_char_read = _getline(&line_ptr, &n);
		if (num_char_read == -1)
		{
			if (line_ptr)
				free(line_ptr);
			exit(0);
		}
		line_ptr = trim_spaces(line_ptr);
		if (!line_ptr)
		{
			free(line_ptr);
			continue;
		}
		if (_strcmp(line_ptr, "exit") == 0)
		{
			free(line_ptr);
			line_ptr = NULL;
			exit(0); } /* line end */
		tokens = create_tokens(line_ptr);
		if (tokens && tokens[0])
		{
			execute_command(tokens);
			free_tokens(tokens);
			wait(&state); } /* line end */
	}
	free(line_ptr);
	return (state);
}
