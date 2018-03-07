/*
** EPITECH PROJECT, 2017
** File Name : line.h
** File description:
** by Arthur Teisseire
*/

#ifndef LINE_H
#define LINE_H

typedef struct buffer buffer_t;
typedef struct token token_t;

typedef struct line {
	int index;
	int nb_bytes;
	int nb_tokens;
	int is_index;
	int is_label;
	token_t *tokens;
} line_t;

int is_index(line_t *line);
int is_label(char *line);
int is_cbyte(line_t *line);
int store_and_check_line(int fd, buffer_t *buffer, int index);
int set_line(line_t *line_data, char *line);
void set_line_bytes(line_t *line);

#endif
