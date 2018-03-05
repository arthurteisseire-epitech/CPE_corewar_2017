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

int my_asm(buffer_t *buffer, char *pathname)
{
	int fd = open(pathname, O_RDONLY);
	char *line = get_next_line(fd);
	int index = 0;

	while (line != NULL) {
		buffer->line = realloc(buffer->line, sizeof(line_t));
		if (set_line(&buffer->line[index], line) == -1)
			return (-1);
		free(line);
		line = get_next_line(fd);
		index++;
	}
	return (0);
}
