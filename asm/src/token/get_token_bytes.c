/*
** EPITECH PROJECT, 2017
** File Name : get_nb_bytes.c
** File description:
** by Arthur Teisseire
*/

#include "asm.h"

static char const index[NB_INDEX][5] = {
	"live",
	"zjmp",
	"sti",
	"ldi",
	"fork",
	"lfork",
	"lldi"
};

static const dict_t type_bytes[] = {
	{REG_CHAR, 1},
	{DIRECT_CHAR, 4}
};

int is_index(line_t *line)
{
	int i = 0;

	while (i < NB_INDEX) {
		if (my_strcmp(line->token[0].str, index[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int get_token_bytes(token_t *token)
{
	
}
