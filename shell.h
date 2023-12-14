#define SHELL_H
#ifndef SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

void _printf(const char *message);
void _prompt(void);
void read_cmd(char *command, size_t size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **_strtok(char *line, char *delim);
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);





#endif
