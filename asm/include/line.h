/*
** EPITECH PROJECT, 2017
** File Name : line.h
** File description:
** by Arthur Teisseire
*/

#include "op.h"

#ifndef LINE_H
#define LINE_H

typedef struct buffer buffer_t;
typedef struct token token_t;

typedef struct line {
	int index;
	int id_bytes;
	int nb_bytes;
	int nb_tokens;
	int is_index;
	token_t *tokens;
	char *binary;
} line_t;

int replace_label_call(buffer_t *buffer, line_t *line);
void overwrite_label_call(line_t *line, int id_tk, int jump_size);
int is_label(char *line);
int is_valid_label(char *line);
int is_label_call(char *line);
int get_label_id(buffer_t *buffer, char *line);
int detect_label_call(line_t *line);
int is_index(line_t *line);
int is_cbyte(line_t *line);
int store_and_check_line(int fd, buffer_t *buffer, int index, header_t *header);
int set_line(line_t *line_data, char *line);
void set_line_bytes(line_t *line);
int set_header1(header_t *header, int fd);

int set_line_binary(line_t *line);
void set_args_binary(line_t *line, token_t *token, int *index_byte);
void set_cbyte(line_t *line);
void set_cmd_binary(line_t *line);
void set_token_binary(token_t *token);

#endif
