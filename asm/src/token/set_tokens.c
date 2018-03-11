/*
** EPITECH PROJECT, 2017
** File Name : set_tokens.c
** File description:
** by Arthur Teisseire
*/

#include "op.h"
#include "my.h"
#include "asm.h"
#include "line.h"
#include "token.h"

static int put_tokens_in_str(line_t *line, char **tokens)
{
	int i = 0;

	while (i != line->nb_tokens) {
		line->tokens[i].str = my_strdup(tokens[i]);
		i++;
	}
	return (0);
}

int set_tokens(line_t *line, char **tokens)
{
	int i = 1;

	if (init_tokens(line, tokens) == -1)
		return (-1);
	put_tokens_in_str(line, tokens);
	line->tokens[0].is_label = is_label(tokens[0]);
	while (i < line->nb_tokens) {
		line->is_index = is_index(line);
		set_token_bytes(line, &line->tokens[i]);
		i++;
	}
	return (0);
}
