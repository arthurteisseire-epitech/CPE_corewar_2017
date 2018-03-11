/*
** EPITECH PROJECT, 2017
** File Name : is_line_valid.c
** File description:
** Ozz
*/

#include "my.h"
#include "op.h"
#include "line.h"
#include "token.h"
#include "parse.h"
#include "errors.h"

int get_arg_type(char *arg)
{
	int reg_nb;

	if (arg[0] == 'r') {
		reg_nb = my_atoi(&arg[1]);
		if (my_str_isnum(&arg[1]) == 1
			&& 0 < reg_nb && reg_nb <= REG_NUMBER) {
			return (T_REG);
		} else {
			put_err_asm(WRONG_REGISTER_NB);
			return (-1);
		}
	} else if (arg[0] == DIRECT_CHAR && my_str_isnum(&arg[1]) == 1) {
		return (T_DIR);
	} else if (my_str_isnum(&arg[1]) == 1) {
		return (T_IND);
	} else {
		put_err_asm(WRONG_INSTRUCT_ARG);
		return (-1);
	}
}

int is_args_valid(int id_cmd, int id_arg, char *arg)
{
	int arg_type = get_arg_type(arg);

	if (arg_type == -1)
		return (-1);
	if ((op_tab[id_cmd].type[id_arg - 1] & arg_type) == 0) {
		put_err_asm(WRONG_INSTRUCT_ARG);
		return (-1);
	}
	return (1);
}

int is_nb_arg_valid(line_t *line, int id_cmd)
{
	if (line->nb_tokens - 1 > op_tab[id_cmd].nbr_args) {
		put_err_asm(WRONG_NB_ARGS);
		return (-1);
	}
	if (line->nb_tokens - 1 < op_tab[id_cmd].nbr_args) {
		put_err_asm(WRONG_INSTRUCT_ARG);
		return (-1);
	}
	return (1);
}

int is_line_valid(line_t *line)
{
	int id_cmd = get_id_cmd(line->tokens[0].str);
	token_t *line_tk = line->tokens;

	if (id_cmd == -1) {
		put_err_asm(INVALID_INSTRUCTION);
		return (-1);
	}
	if (is_nb_arg_valid(line, id_cmd) == -1)
		return (-1);
	for (int id_arg = 1; id_arg < line->nb_tokens; id_arg++) {
		if (is_args_valid(id_cmd, id_arg, line_tk[id_arg].str) == -1)
			return (-1);
	}
	return (1);
}
