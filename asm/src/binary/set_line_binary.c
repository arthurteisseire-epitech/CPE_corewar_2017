/*
** EPITECH PROJECT, 2017
** File Name : set_binary.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "line.h"
#include "token.h"
#include "parse.h"

int set_line_binary(line_t *line)
{
	int index_byte = 0;

	line->binary = malloc(sizeof(char) * line->nb_bytes);
	if (line->binary == NULL)
		return (-1);
	set_cmd_binary(line);
	index_byte++;
	if (is_cbyte(line)) {
		index_byte++;
		set_cbyte(line);
	}
	for (int i = 1; i < line->nb_tokens; i++) {
		set_token_binary(&line->tokens[i]);
		set_args_binary(line, &line->tokens[i], &index_byte);
	}
	return (0);
}

void set_args_binary(line_t *line, token_t *token, int *index_byte)
{
	if (token->nb_bytes == 1) {
		line->binary[*index_byte] = token->value.reg;
		(*index_byte)++;
	} else if (token->nb_bytes == 2) {
		for (int i = 0; i < 2; i++) {
			line->binary[*index_byte] = token->value.reg;
			token->value.dir >>= 8;
			(*index_byte)++;
		}
	} else if (token->nb_bytes == 4) {
		for (int i = 0; i < 4; i++) {
			line->binary[*index_byte] = token->value.reg;
			token->value.dir >>= 8;
			(*index_byte)++;
		}
	}
}

void set_cbyte(line_t *line)
{
	line->binary[1] = 0;
	for (int i = 1; i < line->nb_tokens; i++) {
		line->binary[1] += line->tokens[i].cbyte;
		line->binary[1] <<= 2;
	}
}

void set_cmd_binary(line_t *line)
{
	int id = get_id_cmd(line->tokens[0].str);

	line->binary[0] = op_tab[id].code;
}

void set_token_binary(token_t *token)
{
	if (token->str[0] == REG_CHAR)
		token->value.reg = my_atoi(&token->str[1]);
	else if (token->str[0] == DIRECT_CHAR && token->nb_bytes == 4) {
		token->value.dir = my_atoi(&token->str[1]);
		token->value.dir = REV_INT(token->value.dir);
	} else if (token->str[0] == DIRECT_CHAR && token->nb_bytes == 2) {
		token->value.ind = my_atoi(&token->str[1]);
		token->value.ind = REV_SHORT(token->value.dir);
	} else {
		token->value.ind = my_atoi(token->str);
		token->value.ind = REV_SHORT(token->value.dir);
	}
}
