/*
** EPITECH PROJECT, 2017
** File Name : set_tokens.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

int set_tokens(line_t *line, char **tokens)
{
	int i = 0;

	line->nb_tokens = my_arrlen(tokens);
	line->tokens = malloc(sizeof(token_t) * line->nb_tokens);
	if (line->tokens == NULL) {
		free_array(tokens);
		return (-1);
	}
	while (i < line->nb_tokens) {
		line->tokens[i].str = tokens[i];
		set_token_bytes(line, &line->tokens[i]);
		i++;
	}
	return (0);
}
