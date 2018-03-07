/*
** EPITECH PROJECT, 2018
** ASM corewar
** File description:
** set token in
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "my.h"

static int is_label(char *line)
{
	int i = 0;

	while (is_char_in_str(line[i], LABEL_CHARS))
		i++;
	if (line[i] == LABEL_CHAR && line[i + 1] == '\0')
		return (1);
	return (0);
}

static int set_tokens(line_t *line, char **tokens)
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
		i++;
	}
	return (0);
}

int set_line(line_t *line_data, char *line)
{
	char **tokens = split(line, separators);

	if (tokens == NULL || set_tokens(line_data, tokens) != 0)
		return (-1);
	line_data->label = is_label(tokens[0]);
	return (0);
}
