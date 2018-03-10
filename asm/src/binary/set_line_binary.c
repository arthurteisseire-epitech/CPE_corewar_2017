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
		set_args_binary(line, &line->tokens[i], index_byte);
		index_byte++;
	}
	return (0);
}

void set_args_binary(line_t *line, token_t *token, int index_byte)
{
	if (token->nb_bytes == 1)
		line->binary[index_byte] = token->value.reg;
	else if (token->nb_bytes == 2)
		line->binary[index_byte] = token->value.ind;
	else if (token->nb_bytes == 4)
		line->binary[index_byte] = token->value.dir;
}

void set_cbyte(line_t *line)
{
	int shift_bits = 24;

	for (int i = 1; i < line->nb_tokens; i++) {
		line->binary[1] += (line->tokens[i].cbyte << shift_bits);
		shift_bits -= 8;
	}
}

void set_cmd_binary(line_t *line)
{
	int id = get_id_cmd(line->tokens[0].str);

	line->binary[0] = op_tab[id].code;
}

void set_token_binary(token_t *token)
{
	if (token->str[0] == REG_CHAR || token->str[0] == DIRECT_CHAR)
		token->value.dir = my_atoi(&token->str[1]);
	else
		token->value.dir = my_atoi(token->str);
	token->value.dir = REV_BYTES(token->value.dir);
}
