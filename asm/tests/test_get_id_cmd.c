/*
** EPITECH PROJECT, 2017
** File Name : get_id_cmd_test.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "asm.h"
#include "parse.h"
#include "op.h"

char const separators[3] = {SEPARATOR_CHAR, ' ', 't'};

Test(get_id_cmd, return_index)
{
	cr_expect(get_id_cmd("unknown_cmd") == -1);
	cr_expect(get_id_cmd("live") == 0);
	cr_expect(get_id_cmd("ld") == 1);
	cr_expect(get_id_cmd("st") == 2);
	cr_expect(get_id_cmd("add") == 3);
	cr_expect(get_id_cmd("sub") == 4);
	cr_expect(get_id_cmd("and") == 5);
	cr_expect(get_id_cmd("or") == 6);
	cr_expect(get_id_cmd("xor") == 7);
	cr_expect(get_id_cmd("zjmp") == 8);
	cr_expect(get_id_cmd("ldi") == 9);
	cr_expect(get_id_cmd("sti") == 10);
	cr_expect(get_id_cmd("fork") == 11);
	cr_expect(get_id_cmd("lld") == 12);
	cr_expect(get_id_cmd("lldi") == 13);
	cr_expect(get_id_cmd("lfork") == 14);
	cr_expect(get_id_cmd("aff") == 15);
}

Test(get_id_cmd, is_opt_end)
{
	cr_expect(is_opt_end(&op_tab[0]) == -1);
	cr_expect(is_opt_end(&op_tab[16]) == 1);
}
