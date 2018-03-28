/*
** EPITECH PROJECT, 2017
** File Name : skip_and_set_labels.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "asm.h"
#include "errors.h"
#include "buffer.h"
#include "skip.h"
#include "line.h"

int store_label(buffer_t *buffer, char *label, int index_line)
{
	buffer->nb_labels += 1;
	buffer->labels = realloc(buffer->labels,
		sizeof(label_t) * buffer->nb_labels);
	buffer->labels[buffer->nb_labels - 1].str = label;
	buffer->labels[buffer->nb_labels - 1].line = index_line;
	if (buffer->labels == NULL)
		return (-1);
	return (0);
}

int set_new_line(buffer_t *buffer, char **line, char *end, char *label)
{
	char *tmp_line = *line;

	if (label == NULL) {
		*line = get_next_line(buffer->fd);
		true_index(1);
		if (*line == NULL)
			return (-1);
	} else {
		*line = my_strdup(end);
	}
	free(tmp_line);
	return (0);
}

int set_label_line(buffer_t *buffer, char **line, char const *sep, int index_line)
{
	static char const sep_lab[2] = {LABEL_CHAR, '\0'};
	char *end = *line;
	char *label;

	label = get_next_word(&end, sep_lab);
	my_strip(&label, sep);
	if (label == NULL)
		return (-1);
	if (store_label(buffer, label, index_line) == -1)
		return (-1);
	if (set_new_line(buffer, line, end + 1, label) == -1)
		return (-1);
	return (0);
}

int skip_and_set_labels(buffer_t *buffer, char **line, char const *sep, int index_line)
{
	int lab_char;

	if (*line == NULL)
		exit(0);
	lab_char = is_label_valid(*line, sep);
	if (lab_char == -1) {
		put_err_asm(buffer->lines[index_line].true_index, INVALID_LABEL);
		return (-1);
	} else if (lab_char == 0)
		return (0);
	if (set_label_line(buffer, line, sep, index_line) == -1)
		return (-1);
	return (1);
}
