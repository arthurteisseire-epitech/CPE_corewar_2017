/*
** EPITECH PROJECT, 2017
** File Name : init_tokens.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "buffer.h"
#include "line.h"
#include "token.h"

static int skip_and_set_label(buffer_t *buffer, char **tokens, int is_lab)
{
	if (is_lab) {
		buffer->nb_labels += 1;
		buffer->labels = realloc(buffer->labels, sizeof(label_t) * buffer->nb_labels);
		if (buffer->labels == NULL)
			return (-1);
		buffer->labels[buffer->nb_labels - 1].str = tokens[0];
	}
	return (0);
}

int init_tokens(buffer_t *buffer, line_t *line, char **tokens)
{
	int is_lab = is_label(tokens[0]);

	if (skip_and_set_label(buffer, tokens, is_lab) == -1)
		return (-1);
	line->nb_tokens = my_arrlen(tokens) - is_lab;
	if (line->nb_tokens == 0) {
		return (0);
	}
	line->tokens = malloc(sizeof(token_t) * line->nb_tokens);
	if (line->tokens == NULL)
		return (-1);
	for (int i = 0; i < line->nb_tokens; i++) {
		line->tokens[i].nb_bytes = 0;
		line->tokens[i].is_label = 0;
		line->tokens[i].cbyte = 0;
		line->tokens[i].str = tokens[i + is_lab];
	}
	return (0);
}
