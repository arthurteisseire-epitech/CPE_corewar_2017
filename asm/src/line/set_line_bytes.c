/*
** EPITECH PROJECT, 2017
** File Name : get_line_bytes.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "line.h"
#include "token.h"

static const char no_cbyte_inst[NB_NOCBYTE][6] = {
	"live",
	"zjmp",
	"fork",
	"lfork"
};

int is_cbyte(line_t *line)
{
	for (int i = 0; i < NB_NOCBYTE; i++)
		if (my_strcmp(line->tokens[0].str, no_cbyte_inst[i]) == 0)
			return (0);
	return (1);
}

void set_line_bytes(line_t *line)
{
	line->nb_bytes = is_cbyte(line);
	for (int i = 0; i < line->nb_tokens; i++)
		line->nb_bytes += line->tokens[i].nb_bytes;
}
