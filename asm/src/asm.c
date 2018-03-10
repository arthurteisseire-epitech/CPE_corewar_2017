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

/* TO DO : RETURN CASCADE */

int my_asm(char *pathname)
{
	buffer_t buffer;
	header_t header;
	int status = 0;

	init_buffer(&buffer, pathname);
	if (buffer.fd < 1)
		return (-1);
	set_header(&header, buffer.fd);
	set_buffer(&buffer);
//	status = set_binary(&buffer);
//	if (status == 0)
//		write_binary(&buffer);
//	destroy(&buffer);
	return (status);
}

int set_buffer(buffer_t *buffer)
{
	char *line = get_next_line(buffer->fd);

	skip_comments_and_labels(buffer, &line);
	//set_line(buffer, line);
	return (0);
}

/*
int set_binary(buffer_t *buffer)
{
	for (int i = 0; i < buffer->nb_lines; i++) {
		replace_label_call(buffer, &buffer->lines[i]);
		is_line_valide(&buffer->lines[i]);
		set_binary_line(buffer, &buffer->lines[i]);
	}
}
*/

//int write_binary(buffer_t *buffer)
//{

//}
