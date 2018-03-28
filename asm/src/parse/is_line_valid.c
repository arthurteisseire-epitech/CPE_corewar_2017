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

int get_arg_type(line_t *line, int i)
{
	int reg_nb;
	char *arg = line->tokens[i].str;

	if (arg[0] == 'r') {
		reg_nb = my_atoi(&arg[1]);
		if (my_str_isnum(&arg[1]) == 1
			&& 0 < reg_nb && reg_nb <= REG_NUMBER) {
			return (T_REG);
		} else {
			put_err_asm(line->true_index, WRONG_REGISTER_NB);
			return (-1);
		}
	} else if (arg[0] == DIRECT_CHAR && my_str_isnum(&arg[1]) == 1) {
		return (T_DIR);
	} else if (my_str_isnum(&arg[1]) == 1) {
		return (T_IND);
	} else {
		put_err_asm(line->true_index, WRONG_INSTRUCT_ARG);
		return (-1);
	}
}

int is_args_valid(int id_cmd, int id_arg, line_t *line, int i)
{
	int arg_type = get_arg_type(line, i);

	if (arg_type == -1)
		return (-1);
	if ((op_tab[id_cmd].type[id_arg - 1] & arg_type) == 0) {
		put_err_asm(line->true_index, WRONG_INSTRUCT_ARG);
		return (-1);
	}
	return (arg_type);
}

int is_nb_arg_valid(line_t *line, int id_cmd)
{
	if (line->nb_tokens - 1 > op_tab[id_cmd].nbr_args) {
		put_err_asm(line->true_index, WRONG_NB_ARGS);
		return (-1);
	}
	if (line->nb_tokens - 1 < op_tab[id_cmd].nbr_args) {
		put_err_asm(line->true_index, WRONG_INSTRUCT_ARG);
		return (-1);
	}
	return (1);
}

int arg_type_to_cbyte(int arg_type)
{
	if (arg_type == T_REG)
		return (1);
	if (arg_type == T_DIR)
		return (2);
	if (arg_type == T_IND)
		return (3);
	return (0);
}

int is_line_valid(line_t *line)
{
	int id_cmd = get_id_cmd(line->tokens[0].str);
	token_t *line_tk = line->tokens;
	int arg_type;

	if (id_cmd == -1) {
		put_err_asm(line->true_index, INVALID_INSTRUCTION);
		return (-1);
	}
	if (is_nb_arg_valid(line, id_cmd) == -1)
		return (-1);
	for (int id_arg = 1; id_arg < line->nb_tokens; id_arg++) {
		arg_type = is_args_valid(id_cmd, id_arg, line, id_arg);
		if (arg_type == -1)
			return (-1);
		line_tk[id_arg].cbyte = arg_type_to_cbyte(arg_type);
	}
	return (1);
}
