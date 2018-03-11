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
	"live",
	"zjmp",
	"sti",
	"ldi",
	"fork",
	"lfork",
	"lldi"
};

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
