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

int init_tokens(line_t *line, char **tokens)
{
	line->nb_tokens = my_arrlen(tokens);
	line->tokens = malloc(sizeof(token_t) * line->nb_tokens);
	if (line->tokens == NULL)
		return (-1);
	for (int i = 0; i < line->nb_tokens; i++) {
		line->tokens[i].nb_bytes = 0;
		line->tokens[i].is_label = 0;
		line->tokens[i].cbyte = 0;
		line->tokens[i].str = tokens[i];
	}
	return (0);
}
