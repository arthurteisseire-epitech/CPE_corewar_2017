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
#include "my.h"
#include "skip.h"

int get_cor_name(buffer_t *buffer, char *pathname)
{
	int i = my_strlen(pathname);

	if (my_strcmp(&pathname[i - 2], ".s") != 0)
		return (-1);
	buffer->cor_name = malloc(sizeof(char) * (i + 3));
	if (buffer->cor_name == NULL)
		return (-1);
	my_strcpy(buffer->cor_name, pathname);
	my_strcpy(&buffer->cor_name[i - 1], "cor");
	return (0);
}

int init_buffer(buffer_t *buffer, char *pathname)
{
	buffer->lines = NULL;
	buffer->labels = NULL;
	buffer->cor_name = NULL;
	buffer->nb_lines = 0;
	buffer->curr_byte = 0;
	buffer->nb_labels = 0;
	buffer->fd = open(pathname, O_RDONLY);
	if (buffer->fd == -1)
		return (-1);
	if (get_cor_name(buffer, pathname) != 0)
		return (-1);
	return (0);
}
