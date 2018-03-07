/*
** EPITECH PROJECT, 2017
** File Name : is_line_valid.c
** File description:
** Ozz
*/

#include "op.c"
#include "op.h"
#include "asm.h"
#include "parse.h"

int is_line_valid(line_t *line)
{
	if (get_id_cmd(op_tab, line->tokens[0]->str) == -1)
		return (-1);
	return (1);
}
