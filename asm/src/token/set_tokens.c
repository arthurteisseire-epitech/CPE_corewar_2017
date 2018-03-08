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

	line->nb_tokens = my_arrlen(tokens);
	line->tokens = malloc(sizeof(token_t) * line->nb_tokens);
	if (line->tokens == NULL) {
		free_array(tokens);
		return (-1);
	}
	//line->tokens[0].is_label = is_label(tokens[0]);
	//printf("IS_LABEL : %d\n",line->tokens[0].is_label);
	while (i < line->nb_tokens) {
		init_token(&line->tokens[i]);
		line->tokens[i].str = tokens[i];
		line->is_index = is_index(line);
		set_bytes(line, i);
		i++;
	}
	return (0);
}
