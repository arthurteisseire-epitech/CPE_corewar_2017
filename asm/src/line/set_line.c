/*
** EPITECH PROJECT, 2018
** ASM corewar
** File description:
** set token in
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"
#include "line.h"
#include "token.h"

static char const index[NB_INDEX][6] = {
	"zjmp",
	"sti",
	"ldi",
	"fork",
	"lfork",
	"lldi"
};

int set_line(line_t *line_struct, char *line)
{
	char **tokens_arr = split(line, separators);
	int i = 0;

	line_struct->binary = NULL;
	line_struct->nb_tokens = my_arrlen(tokens_arr);
	line_struct->id_bytes = 0;
	line_struct->true_index = true_index(0);
	while (i != line_struct->nb_tokens) {
		set_tokens(line_struct, tokens_arr);
		i++;
	}
	set_line_bytes(line_struct);
	free_array(tokens_arr);
	return (0);
}

int is_index(line_t *line)
{
	int i = 0;

	while (i < NB_INDEX) {
		if (my_strcmp(line->tokens[0].str, index[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
