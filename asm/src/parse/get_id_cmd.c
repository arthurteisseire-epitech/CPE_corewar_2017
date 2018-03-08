/*
** EPITECH PROJECT, 2017
** File Name : get_id_cmd.c
** File description:
** Ozz
*/

#include "my.h"
#include "op.h"

int is_opt_end(op_t *opt)
{
	if (opt->mnemonique == 0 &&
		opt->nbr_args == 0 &&
		opt->type[0] == 0 &&
		opt->code == 0 &&
		opt->nbr_cycles == 0 &&
		opt->comment == 0) {
		return (1);
	} else {
		return (-1);
	}
}

int get_id_cmd(char *cmd)
{
	int id = 0;

	while (is_opt_end(&op_tab[id]) == -1) {
		if (my_strcmp(cmd, op_tab[id].mnemonique) == 0)
			return (id);
		id++;
	}
	return (-1);
}
