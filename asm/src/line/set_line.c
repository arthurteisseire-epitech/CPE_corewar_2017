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

static char const index[NB_INDEX][6] = {
	"live",
	"zjmp",
	"sti",
	"ldi",
	"fork",
	"lfork",
	"lldi"
};

static int is_index(line_t *line)
{
	int i = 0;

	while (i < NB_INDEX) {
		if (my_strcmp(line->tokens[0].str, index[i]) == 0)
			return (1);
		i++;
	}
	return (0); }

static int is_label(char *line)
{
	int i = 0;

	while (is_char_in_str(line[i], LABEL_CHARS))
		i++;
	if (line[i] == LABEL_CHAR && line[i + 1] == '\0')
		return (1);
	return (0);
}

int set_line(line_t *line_data, char *line)
{
	char **tokens = split(line, separators);

	if (tokens == NULL || set_tokens(line_data, tokens) != 0)
		return (-1);
	line_data->is_label = is_label(tokens[0]);
	line_data->is_index = is_index(line_data);
	return (0);
}
