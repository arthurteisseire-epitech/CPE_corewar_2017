/*
** EPITECH PROJECT, 2017
** File Name : get_id_cmd.c
** File description:
** Ozz
*/
#include "my.h"
#include "op.h"

int get_id_cmd(op_t *op_tab, char *cmd)
{
	int id;
	for (int i = 0; op_tab[i].code != 0; i++) {
		id = my_strcmp(cmd, op_tab[i].mnemonique);
		if (id == 0)
			return (id);
	}
	return (-1);
}
