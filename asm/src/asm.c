/*
** EPITECH PROJECT, 2017
** File Name : asm.c
** File description:
** by Arthur Teisseire
*/

#include <fcntl.h>
#include "buffer.h"
#include "my.h"
#include "op.h"
#include "line.h"
#include "asm.h"

/* TO DO : RETURN CASCADE */

/*int set_buffer(buffer_t *buffer, int fd)
{
	char *line = get_next_line(fd);

	skip_comments_and_labels(buffer, &line, fd);
	set_line(buffer, line);
}


int set_binary(buffer_t *buffer)
{
	for (int i = 0; i < buffer->nb_lines; i++) {
		replace_label_call(buffer, &buffer->lines[i]);
		is_line_valide(&buffer->lines[i]);
		set_binary_line(buffer, &buffer->lines[i]);
	}
}*/

int my_asm(char *pathname)
{
	buffer_t buffer;
	header_t header;
	int fd = open(pathname, O_RDONLY);
	int status = 0;

	if (fd < 1)
		return (-1);
	set_header(&header, fd);
//	set_buffer(&buffer, fd);
//	status = set_binary(&buffer);
//	if (status == 0)
//		write_binary(&buffer);
//	destroy(&buffer);
	return (status);
}

//int write_binary(buffer_t *buffer)
//{

//}
