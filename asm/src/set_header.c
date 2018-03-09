/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** manage header
*/

#include <stdlib.h>
#include "parse.h"
#include "my.h"
#include "op.h"
#include "line.h"
#include "asm.h"
#include "errors.h"
#include "token.h"

#include <stdio.h>
static int check_str(line_t *line)
{
	if ((my_strcmp(NAME_CMD_STRING, line->tokens[0].str) != 0 &&
		my_strcmp(COMMENT_CMD_STRING, line->tokens[0].str) != 0) &&
		get_id_cmd(line->tokens[0].str) == -1) {
		put_err_asm(INVALID_INSTRUCTION, line->index);
		return (-1);
	} else if (line->nb_tokens > 2 || (line->nb_tokens > 1 && (line->tokens[1].str[0] != '"' ||
		line->tokens[1].str[my_strlen(line->tokens[1].str) - 1] != '"'))) {
		put_err_asm(SYNTAX_ERROR, line->index);
		return (-2);
	}
	return (0);
}

static int set_name(line_t *line, header_t *header)
{
	char *name;

	if (my_strcmp(NAME_CMD_STRING, line->tokens[0].str) == 0) {
		if (line->nb_tokens == 1) {
			put_err_asm(NO_NAME ,line->index);
			return (-1);
		}
		name = get_next_word(&line->tokens[1].str, "\"");
		my_strcpy(header->prog_name, name);
		free(name);
		return (0);
	}
	return (-1);

}

static int set_comment(line_t *line, header_t *header)
{
	char *comment;

	if (my_strcmp(NAME_CMD_STRING, line->tokens[0].str) == 0){
		put_err_asm(MISPLACED_COMMENT, line->index);
	}
	else if (my_strcmp(COMMENT_CMD_STRING, line->tokens[0].str) == 0) {
		if (line->nb_tokens == 1) {
			put_err_asm(EMPTY_COMMENT, line->index);
			return (-1);
		}
		comment = get_next_word(&line->tokens[1].str, "\"");
		my_strcpy(header->prog_name, comment);
		free(comment);
		return (0);
	}
	return (-1);
}

int set_header(line_t *line, header_t *header)
{
	if (check_str(line) != 0)
		return (-1);
	if (line->index == 0)
		return (set_name(line, header));
	else if (line->index == 1)
		return (set_comment(line, header));
	else
		return (-1);
}
