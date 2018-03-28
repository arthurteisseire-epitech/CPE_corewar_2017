/*
** EPITECH PROJECT, 2017
** File Name : set_buffer.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"
#include "buffer.h"
#include "line.h"
#include "my.h"
#include "skip.h"

int set_buffer(buffer_t *buffer)
{
	char *line = get_next_line(buffer->fd);
	int index = 0;

	buffer->lines = NULL;
	while (line != NULL) {
		set_buffer_line(buffer, &line, index);
		index++;
	}
	buffer->nb_lines = index;
	set_buffer_bytes(buffer);
	return (0);
}

int set_buffer_line(buffer_t *buffer, char **line, int index)
{
	line_t *lines;
	int status;

	status = skip_comments_and_labels(buffer, line, index);
	if (status != 0)
		return (status);
	buffer->lines = realloc(buffer->lines,
		sizeof(line_t) * (index + 1));
	lines = buffer->lines;
	lines[index].index = index;
	set_line(&buffer->lines[index], *line);
	if (index != 0)
		lines[index].id_bytes = lines[index - 1].id_bytes +
		lines[index - 1].nb_bytes;
	*line = get_next_line(buffer->fd);
	true_index(1);
	return (0);
}
