#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int ac, char **argv);
char *_strcpy(char *line_ptr);
int _strlen(char *str);
int num_tokens(char *line_ptr);
void execute(char **argv);
char **create_tokens(char *lineptr);
void execute_command(char **argv);
void free_tokens(char **tokens);

#endif
