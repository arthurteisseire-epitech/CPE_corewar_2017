/*
** EPITECH PROJECT, 2017
** File Name : write_binary.c
** File description:
** by Arthur Teisseire
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "buffer.h"
#include "line.h"

int write_binary(buffer_t *buffer, header_t *header)
{
	int fd_cor = open(buffer->cor_name, O_CREAT | O_WRONLY | O_TRUNC,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	int index_buffer = 0;

	buffer->binary = malloc(sizeof(char) * buffer->nb_bytes);
	if (buffer->binary == NULL)
		return (-1);
	for (int i = 0; i < buffer->nb_lines; i++)
		fill_buffer_binary(buffer, &buffer->lines[i], &index_buffer);
	header->prog_size = REV_INT(buffer->nb_bytes);
	write(fd_cor, header, sizeof(header_t));
	write(fd_cor, buffer->binary, buffer->nb_bytes);
	return (0);
}

void fill_buffer_binary(buffer_t *buffer, line_t *line, int *index_buffer)
{
	for (int i = 0; i < line->nb_bytes; i++) {
		buffer->binary[*index_buffer] = line->binary[i];
		(*index_buffer)++;
	}
}
