/*
** EPITECH PROJECT, 2017
** File Name : get_id_cmd_test.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"
#include "parse.h"
#include "op.h"
#include <stdio.h>

char const separators[3] = {SEPARATOR_CHAR, ' ', '\t'};

Test(get_id_cmd, return_index)
{
	cr_expect(get_id_cmd(op_tab, "unknown_cmd") == -1);
	cr_expect(get_id_cmd(op_tab, "live") == 0);
	cr_expect(get_id_cmd(op_tab, "ld") == 1);
	cr_expect(get_id_cmd(op_tab, "st") == 2);
	cr_expect(get_id_cmd(op_tab, "add") == 3);
	cr_expect(get_id_cmd(op_tab, "sub") == 4);
	cr_expect(get_id_cmd(op_tab, "and") == 5);
	cr_expect(get_id_cmd(op_tab, "or") == 6);
	cr_expect(get_id_cmd(op_tab, "xor") == 7);
	cr_expect(get_id_cmd(op_tab, "zjmp") == 8);
	cr_expect(get_id_cmd(op_tab, "ldi") == 9);
	cr_expect(get_id_cmd(op_tab, "sti") == 10);
	cr_expect(get_id_cmd(op_tab, "fork") == 11);
	cr_expect(get_id_cmd(op_tab, "lld") == 12);
	cr_expect(get_id_cmd(op_tab, "lldi") == 13);
	cr_expect(get_id_cmd(op_tab, "lfork") == 14);
	cr_expect(get_id_cmd(op_tab, "aff") == 15);
}

Test(get_id_cmd, is_opt_end)
{
	cr_expect(is_opt_end(op_tab[0]) == -1);
	cr_expect(is_opt_end(op_tab[16]) == 1);
}
