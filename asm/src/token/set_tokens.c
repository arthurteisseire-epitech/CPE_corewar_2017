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

static void set_bytes(line_t *line, int i)
{
	if (i >= 1)
		set_token_bytes(line, &line->tokens[i]);
	else if (line->tokens[0].is_label == 1)
		line->tokens[0].nb_bytes = 0;
	else
		line->tokens[0].nb_bytes = 1;
}

int set_tokens(line_t *line, char **tokens)
{
	int i = 0;

	if (init_tokens(line, tokens) == -1)
		return (-1);
	while (i < line->nb_tokens) {
		set_token(line, i);
		i++;
	}
	return (0);
}

int set_token(line_t *line, int i)
{
	line->tokens[0].is_label = is_label(line->tokens[0].str);
	line->is_index = is_index(line);
	set_bytes(line, i);
	return (0);
}
