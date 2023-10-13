#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int ac, char **argv);
char *_strcpy(char *line_ptr);
char *_strcpy2(char *dest, char *src);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strcmp(char *s1, char *s2);

/** main function **/
int num_tokens(char *line_ptr);
char **create_tokens(char *lineptr);
void execute_command(char **argv);
void execute(char *cmd, char **argv);
void free_tokens(char **tokens);
char *get_address(char *cmd_copy);
char *check_dir(char *path_token, char *cmd_copy, int cmd_length);
char *check_cmd(char *cmd_copy);

#endif
