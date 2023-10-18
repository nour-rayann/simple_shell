#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#define MAX_LINE_LENGTH 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> /* wait */
#include <sys/stat.h> /* fstat */
#include <ctype.h>

int main(void);

/***** built-in handling *****/
/**
* struct builtin_s - Builtin struct
* @name: name of builtin (string).
* @f: function pointer
*/
typedef struct builtin_s
{
	char *name;
	int (*f)(char **);
} builtin_t;

int (*get_builtin(char *cmd))(char **);

/* for global environment variable(s) */
extern char **environ;

/* custom functions */
char *_strcpy(char *line_ptr);
char *_strcpy2(char *dest, char *src);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strcmp(char *s1, char *s2);

/* token handling */
int num_tokens(char *line_ptr);
char **create_tokens(char *lineptr);
void free_tokens(char **tokens);

/* command execution */
int execute_command(char **argv);
int execute(char *cmd, char **argv);
int is_builtin_cmd(char *cmd_copy);
int execute_builtin_cmd(char *cmd_copy, char **argv);
int execute_external_cmd(char *cmd, char **argv);

/* PATH handling */
char *get_address(char *cmd_copy);
char *check_dir(char *path_token, char *cmd_copy, int cmd_length);
char *check_cmd(char *cmd_copy);

/* environment */
int cmp_env_name(const char *nenv, const char *name);
char *_getenv(const char *name);
int _env(char **environ);

/*handle spaces*/
char *trim_spaces(char *cmd);

/* input */
ssize_t _getline(char **command_buff, size_t *n);

#endif
