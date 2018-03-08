/*
** EPITECH PROJECT, 2017
** File Name : set_tokens.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "asm.h"
#include "line.h"
#include "token.h"

int is_label(char *line)
{
	int i = 0;

	while (is_char_in_str(line[i], LABEL_CHARS))
		i++;
	if (line[i] == LABEL_CHAR && line[i + 1] == '\0')
		return (1);
	return (0);
}

int set_tokens(buffer_t *buffer, line_t *line, char **tokens)
{
	int i = 1;

	if (init_tokens(buffer, line, tokens) == -1)
		return (-1);
	line->tokens[0].is_label = is_label(tokens[0]);
	while (i < line->nb_tokens) {
		line->is_index = is_index(line);
		set_token_bytes(line, &line->tokens[i]);
		i++;
	}
	return (0);
}
