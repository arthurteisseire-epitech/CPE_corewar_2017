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

int my_asm(char *pathname)
{
	buffer_t buffer;
	header_t header;
	int status = 0;

	if (init_buffer(&buffer, pathname) == -1 ||
	set_header1(&header, buffer.fd) == -1 ||
	set_buffer(&buffer) == -1) {
		free_buffer(&buffer);
		return (-1);
	}
	status = set_binary(&buffer);
	header.magic = REV_INT(header.magic);
	if (status == 0)
		write_binary(&buffer, &header);
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
	line_t *lines;

	buffer->lines = NULL;
	while (line != NULL) {
		if (skip_comments_and_labels(buffer, &line, index) == -1)
			return (-1);
		buffer->lines = realloc(buffer->lines,
			sizeof(line_t) * (index + 1));
		lines = buffer->lines;
		lines[index].index = index;
		lines[index].id_bytes = 0;
		lines[index].true_index = true_index(0);
		set_line(&buffer->lines[index], line);
		if (index != 0)
			lines[index].id_bytes = lines[index - 1].id_bytes +
			lines[index - 1].nb_bytes;
		line = get_next_line(buffer->fd);
		true_index(1);
		index++;
	}
	buffer->nb_lines = index;
	set_buffer_bytes(buffer);
	return (0);
}

int set_binary(buffer_t *buffer)
{
	for (int i = 0; i < buffer->nb_lines; i++) {
		if (replace_label_call(buffer, &buffer->lines[i]))
			return (-1);
		if (is_line_valid(&buffer->lines[i]) == -1)
			return (-1);
		set_line_binary(&buffer->lines[i]);
	}
	return (0);
}
