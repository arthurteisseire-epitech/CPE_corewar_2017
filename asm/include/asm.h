/*
** EPITECH PROJECT, 2017
** File Name : asm.h
** File description:
** by Arthur Teisseire
*/

#ifndef ASM_H
#define ASM_H

#define FEND 42

typedef struct label {
	char *label;
	int line;
} label_t;

typedef struct token {
	char *str;
	int type;
	int cbyte;
} token_t;

typedef struct line {
	int label;
	int index;
	int nb_bytes;
	int nb_tokens;
	token_t *tokens;
} line_t;

typedef struct buffer {
	line_t *line;
	label_t *label;
	int curr_byte;
	int nb_lines;
} buffer_t;

int my_asm(buffer_t *buffer, char *pathname);
int store_and_check_line(int fd, buffer_t *buffer, int index);
int set_line(line_t *line_data, char *line);
void init_buffer(buffer_t *buffer);
int skip_comments(int fd, char **line, char *separators);
int is_comment(char *line, char *separators);

extern char const separators[3];

#endif
