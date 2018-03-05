/*
** EPITECH PROJECT, 2018
** ASM corewar
** File description:
** set token in 
*/

#include "asm.h"
#include "op.h"
#include "my.h"

#define CONCAT(A,B,C) A ## B ## C

static int is_label(char *line)
{
	int i = 0;

	while (is_char_in_str(line[i], LABEL_CHARS))
		i++;
	if (line[i] == LABEL_CHAR)
		return (1);
	return (0);
}

static int set_tokens(line_t *line, char **tokens)
{
	int i = 0;

	line->nb_tokens = my_arrlen(tokens);
	line->tokens = malloc(sizeof(token_t) * line->nb_tokens);
	if (line->tokens == NULL) {
		free_array(token);
		return (-1);
	}
	while (i < line->nb_tokens) {
		line->tokens[i] = tokens[i];
		i++;
	}
	return (0);
}

int set_line(line_t *line, char *line)
{
	char **tokens = split(line, CONCAT(SEPARATOR_CHAR, ' ', '\t'));

	if (set_tokens(line, tokens) != 0 || token == NULL)
		return (-1);
	line->label = is_label(token[0]);
	return (0);
}

int main ()
{
	return(0);
}