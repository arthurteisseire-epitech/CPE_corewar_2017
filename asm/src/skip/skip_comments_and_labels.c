/*
** EPITECH PROJECT, 2017
** File Name : skip_comments_and_labels.c
** File description:
** by Arthur Teisseire
*/

#include "buffer.h"
#include "skip.h"

int skip_comments_and_labels(buffer_t *buffer, char **line, int index_line)
{
	int is_label = 1;

	while (is_label) {
		if (skip_comments(buffer->fd, line, " \t") == -1)
			return (-1);
		is_label = skip_and_set_labels(buffer, line, " \t", index_line);
		if (is_label == -1)
			return (-1);
	}
	return (is_label);
}
