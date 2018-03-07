/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** manage header
*/

#include "my.h"
#include "asm.h"

static int check_str(line_t *line)
{
	if ((my_strcmp(NAME_CMD_STRING, line->tokens[0].str) != 0 || my_strcmp(COMMENT_CMD_STRING, line->tokens[0].str) != 0) && get_id_cmd(line->tokens[0].str) == -1)
		//invalide arg
		return (-1);
	else if (line->nb_tokens > 2 || line->tokens[1].str[0] != '"' || line->tokens[1].str[my_strlen(line->tokens[1].str - 1)] != '"')
		//syntax error
		return (-2);
	else
		return (0);
}

static int set_name(line_t *line, header_t *header)
{
	char *name;

	if (my_strcmp(NAME_CMD_STRING, line->tokens[0].str) == 0) {
		name = get_next_word(&line->tokens[1].str, "\"");
		my_strcpy(header->prog_name, name);
		free(name);
		return (0);
	}

}

static int set_comment(line_t *line, header_t *header)
{
	char *comment;

	if (my_strcmp(NAME_CMD_STRING, line->tokens[0].str) == 0){
		//comment doit etre placé avant le name
	}
	else if (my_strcmp(COMMENT_CMD_STRING, line->tokens[0].str) == 0) {
		comment = get_next_word(&line->tokens[1].str, "\"");
		my_strcpy(header->prog_name, comment);
		free(comment);
		return (0);
	}
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