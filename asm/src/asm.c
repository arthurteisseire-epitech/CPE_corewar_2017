/*
** EPITECH PROJECT, 2017
** File Name : asm.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "op.h"
#include "asm.h"
#include "parse.h"
#include "buffer.h"
#include "line.h"

int my_asm(buffer_t *buffer, char *pathname)
{
	int fd = open(pathname, O_RDONLY);
	int status = 0;
	int index = 0;
	header_t *header = malloc(sizeof(header_t));

	if (fd == -1)
		return (-1);
	init_buffer(buffer);
	while (status != FEND && status != -1) {
		status = store_and_check_line(fd, buffer, index, header);
		index++;
	}
	set_buffer_bytes(buffer);
	write(open("test.cor", O_WRONLY), *header, sizeof(header_t));
	return (status);
}

int store_and_check_line(int fd, buffer_t *buffer, int index, header_t *header)
{
	char *line;

	line = get_next_line(fd);
	if (skip_comments(fd, &line, " \t") == FEND)
		return (FEND);
	buffer->lines = realloc(buffer->lines, sizeof(line_t) * (index + 1));
	if (buffer->lines == NULL)
		return (-1);
	buffer->lines[index].index = index;
	if (set_line(buffer, &buffer->lines[index], line) == -1)
		return (-1);
	if (index < 2)
		if (set_header(&buffer->lines[index], header) == -1)
			printf("conard\n");
	buffer->nb_lines += 1;
	if (line != NULL)
		free(line);
	return (0);
}
