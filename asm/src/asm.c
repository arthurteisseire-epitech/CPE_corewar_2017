/*
** EPITECH PROJECT, 2017
** File Name : asm.c
** File description:
** by Arthur Teisseire
*/

#include <fcntl.h>
#include "my.h"
#include "asm.h"
#include "op.h"
#include "buffer.h"
#include "line.h"
#include "skip.h"
#include "free.h"
#include "token.h"
#include "parse.h"

#include <stdio.h>

static void print_tokens(buffer_t *buffer)
{
	int i = 0;
	int j = 0;
	line_t *line;

	while (i < buffer->nb_lines) {
		j = 0;
		line = &buffer->lines[i];
		while (j < line->nb_tokens) {
			printf("LINE[%d] -> TOKEN[%d] : %s\n", i, j, line->tokens[j].str);
			j++;
		}
		i++;
	}
}

static void print_labels(buffer_t *buffer)
{
	for (int i = 0; i < buffer->nb_labels; i++)
		printf("LABELS[%d] : %s\n", i, buffer->labels[i].str);
}

int my_asm(char *pathname)
{
	buffer_t buffer;
	header_t header;
	int status = 0;

	if (init_buffer(&buffer, pathname) == -1) {
		free_buffer(&buffer);
		return (-1);
	}
	if (set_header1(&header, buffer.fd) == -1) {
		free_buffer(&buffer);
		return (-1);
	}
	if (set_buffer(&buffer) == -1) {
		free_buffer(&buffer);
		return (-1);
	}
	print_tokens(&buffer);
	print_labels(&buffer);
	status = set_binary(&buffer);
	if (status == 0)
		write_binary(&buffer);
	free_buffer(&buffer);
	return (status);
}

int set_line(line_t *line_struct, char *line)
{
	char **tokens_arr = split(line, separators);
	int i = 0;

	line_struct->binary = NULL;
	line_struct->nb_tokens = my_arrlen(tokens_arr);
	while (i != line_struct->nb_tokens) {
		set_tokens(line_struct, tokens_arr);
		i++;
	}
	set_line_bytes(line_struct);
	free_array(tokens_arr);
	return (0);
}

int set_buffer(buffer_t *buffer)
{
	char *line = get_next_line(buffer->fd);
	int index = 0;

	buffer->lines = NULL;
	while (line != NULL) {
		if (skip_comments_and_labels(buffer, &line) == -1)
			return (-1);
		buffer->lines = realloc(buffer->lines,
			sizeof(line_t) * (index + 1));
		buffer->lines[index].index = index;
		set_line(buffer->lines, line);
		line = get_next_line(buffer->fd);
		index++;
	}
	buffer->nb_lines = index - 1;
	set_buffer_bytes(buffer);
	print_tokens(buffer);
	return (0);
}

int set_binary(buffer_t *buffer)
{
	for (int i = 0; i < buffer->nb_lines; i++) {
		replace_label_call(buffer, &buffer->lines[i]);
		is_line_valid(&buffer->lines[i]);
		set_line_binary(&buffer->lines[i]);
	}
	return (0);
}
