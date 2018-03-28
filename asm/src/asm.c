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
	set_header1(&header, buffer.fd) == -1) {
		free_buffer(&buffer);
		return (-1);
	}
	status = set_buffer(&buffer);
	if (status != 0)
		return (status);
	status = set_binary(&buffer);
	header.magic = REV_INT(header.magic);
	if (status == 0)
		write_binary(&buffer, &header);
	free_buffer(&buffer);
	return (status);
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
