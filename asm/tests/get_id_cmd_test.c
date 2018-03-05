/*
** EPITECH PROJECT, 2017
** File Name : get_id_cmd_test.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parse.h"
#include "op.h"

Test(get_id_cmd, )
{
	cr_expect(get_id_cmd(op_tab, "live") == 1);
	cr_expect(get_id_cmd(op_tab, "ld") == 2);
	cr_expect(get_id_cmd(op_tab, "st") == 3);
	cr_expect(get_id_cmd(op_tab, "add") == 4);
	cr_expect(get_id_cmd(op_tab, "sub") == 5);
	cr_expect(get_id_cmd(op_tab, "and") == 6);
	cr_expect(get_id_cmd(op_tab, "or") == 7);
	cr_expect(get_id_cmd(op_tab, "xor") == 8);
	cr_expect(get_id_cmd(op_tab, "ldi") == 9);
	cr_expect(get_id_cmd(op_tab, "sti") == 10);
	cr_expect(get_id_cmd(op_tab, "fork") == 11);
	cr_expect(get_id_cmd(op_tab, "lld") == 12);
	cr_expect(get_id_cmd(op_tab, "lldi") == 13);
	cr_expect(get_id_cmd(op_tab, "lfor") == 14);
	cr_expect(get_id_cmd(op_tab, "aff") == 15);
}
