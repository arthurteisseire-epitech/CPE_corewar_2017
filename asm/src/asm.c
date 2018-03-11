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

/* TO DO : RETURN CASCADE */

int my_asm(char *pathname)
{
	buffer_t buffer;
	header_t header;
	int status = 0;

	if (init_buffer(&buffer, pathname) == -1) {
		free_buffer(&buffer);
		return (-1);
	}
	if (set_header(&header, buffer.fd) == -1) {
		free_buffer(&buffer);
		return (-1);
	}
	if (set_buffer(&buffer) == -1) {
		free_buffer(&buffer);
		return (-1);
	}
	//	status = set_binary(&buffer);
	//	if (status == 0)
	//		write_binary(&buffer);
	free_buffer(&buffer);
	return (status);
}

int set_buffer(buffer_t *buffer)
{
	char *line = get_next_line(buffer->fd);

	if (skip_comments_and_labels(buffer, &line) == -1)
		return (-1);
	//set_line(buffer, line);
	return (0);
}

/*
   int set_binary(buffer_t *buffer)
   {
   for (int i = 0; i < buffer->nb_lines; i++) {
   replace_label_call(buffer, &buffer->lines[i]);
   is_line_valide(&buffer->lines[i]);
   set_line_binary(buffer, &buffer->lines[i]);
   }
   }
   */

//int write_binary(buffer_t *buffer)
//{

//}
