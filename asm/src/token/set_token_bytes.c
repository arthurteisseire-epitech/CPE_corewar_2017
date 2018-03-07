/*
** EPITECH PROJECT, 2017
** File Name : get_nb_bytes.c
** File description:
** by Arthur Teisseire
*/

#include "op.h"
#include "asm.h"
#include "line.h"
#include "token.h"

void set_token_bytes(line_t *line, token_t *token)
{
	if (token->str[0] == REG_CHAR) {
		token->nb_bytes = 1;
	} else if (token->str[0] == DIRECT_CHAR) {
		if (line->is_index)
			token->nb_bytes = 2;
		else
			token->nb_bytes = 4;
	} else {
		token->nb_bytes = 2;
	}
}
