/*
** EPITECH PROJECT, 2017
** File Name : label.c
** File description:
** Ozz
*/

#include "line.h"
#include "token.h"
#include "buffer.h"
#include "op.h"
#include "my.h"

int is_valid_label(char *line)
{
	int i = 0;

	while (is_char_in_str(line[i], LABEL_CHARS))
		i++;
	if (line[i] == LABEL_CHAR && line[i + 1] == '\0')
		return (1);
	return (0);
}

int is_label_call(char *line)
{
	int i = 2;

	if (line[0] == '%' && line[1] == LABEL_CHAR) {
		while (is_char_in_str(line[i], LABEL_CHARS))
			i++;
		if (line[i] == '\0')
			return (1);
	}
	return (0);
}

int get_label_id(buffer_t *buffer, char *label)
{
	for (int i = 0; i < buffer->nb_labels; i++) {
		if (my_strcmp(buffer->labels[i].str, label) == 0)
			return (i);
	}
	return (-1);
}

int detect_label_call(line_t *line)
{
	for (int i = 0; i < line->nb_tokens; i++) {
		if (is_label_call(line->tokens[i].str) == 1)
			return (i);
	}
	return (0);
}
