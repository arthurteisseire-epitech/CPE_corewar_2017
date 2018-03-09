/*
** EPITECH PROJECT, 2017
** File Name : asm.c
** File description:
** by Arthur Teisseire
*/

#include <fcntl.h>
#include "asm.h"

/* TO DO : RETURN CASCADE */
int my_asm(char *pathname)
{
	buffer_t buffer;
	header_t header;
	int fd = open(pathname, O_RDONLY);
	int status;

	set_header(&header, fd);
	set_buffer(&buffer, fd);
	status = set_binary(&buffer);
	if (status == 0)
		write_binary(&buffer);
	destroy(&buffer);
	return (status);
}

int set_header(header_t *header, int fd)
{

}

int set_buffer(buffer_t *buffer, int fd)
{
	char *line = get_next_line(fd);

	skip_comments_and_labels(buffer, &line, fd);
	set_line(buffer, line);
}

int set_binary(buffer_t *buffer)
{
	for (int i = 0; i < buffer->nb_lines; i++) {
		replace_label_call(buffer, &buffer->line[i]);
		is_line_valide(&buffer->line[i]);
		set_binary_line(buffer, &buffer->line[i]);
	}
}

int write_binary(buffer_t *buffer)
{

}
