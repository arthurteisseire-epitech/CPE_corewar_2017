/*
** EPITECH PROJECT, 2017
** File Name : replace_label.c
** File description:
** Ozz
*/

#include <stdlib.h>
#include "line.h"
#include "my.h"
#include "op.h"
#include "buffer.h"
#include "token.h"
#include "errors.h"

void overwrite_label_call(line_t *line, int id_tk, int jump_size)
{
	char *jump_str = my_itoa(jump_size);
	char *new_label_call = malloc(sizeof(char) * (my_strlen(jump_str) + 2));

	new_label_call[0] = '%';
	for (int i = 0; jump_str[i] != '\0'; i++) {
		new_label_call[i + 1] = jump_str[i];
	}
	free(line->tokens[id_tk].str);
	line->tokens[id_tk].str = new_label_call;
}

int replace_label_call(buffer_t *buffer, line_t *line)
{
	int label_call_id = detect_label_call(line);
	int label_id;
	int index_label_line;

	if (label_call_id == 0) {
		return (0);
	} else {
		label_id = get_label_id(buffer,
		&line->tokens[label_call_id].str[2]);
		if (get_label_id(buffer,
			line->tokens[label_call_id].str) == 0) {
			put_err_asm(INVALID_LABEL);
			return (-1);
		}
	index_label_line = buffer->lines[buffer->labels[label_id].line].id_bytes;
	overwrite_label_call(line, label_call_id,
			index_label_line - line->id_bytes);
	return (0);
	}
}
