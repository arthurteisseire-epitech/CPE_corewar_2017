/*
** EPITECH PROJECT, 2017
** File Name : init_buffer.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"
#include "buffer.h"
#include "line.h"

int init_buffer(buffer_t *buffer, char *pathname)
{
	buffer->lines = NULL;
	buffer->labels = NULL;
	buffer->nb_lines = 0;
	buffer->curr_byte = 0;
	buffer->nb_labels = 0;
	buffer->fd = open(pathname, O_RDONLY);
	if (buffer->fd == -1)
		return (-1);
	buffer->fd_cor = open()
	return (0);
}
