/*
** EPITECH PROJECT, 2017
** File Name : asm.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "asm.h"
#include "parse.h"

int my_asm(buffer_t *buffer, char *pathname)
{
	int fd = open(pathname, O_RDONLY);
	int status = 0;
	int index = 0;

	if (fd == -1)
		return (-1);
	init_buffer(buffer);
	while (status != FEND && status != -1) {
		status = store_and_check_line(fd, buffer, index);
		index++;
	}
	return (status);
}

int store_and_check_line(int fd, buffer_t *buffer, int index)
{
	char *line;

	line = get_next_line(fd);
	if (skip_comments(fd, &line, " \t") == FEND)
		return (FEND);
	buffer->line = realloc(buffer->line, sizeof(line_t) * (index + 1));
	if (buffer->line == NULL)
		return (-1);
	buffer->line[index].index = index;
	if (set_line(&buffer->line[index], line) == -1)
		return (-1);
	buffer->nb_lines += 1;
	if (line != NULL)
		free(line);
	return (0);
}
