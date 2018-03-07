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

Test(is_line_valid, is_line_valid)
{
	line_t *line = malloc(sizeof(line_t));

	set_line(line, "live, r4");
	cr_expect(is_line_valid(line) == 1);
	set_line(line, "live, %4");
	cr_expect(is_line_valid(line) == -1);
	set_line(line, "live, r4, r1");
	cr_expect(is_line_valid(line) == -1);
	set_line(line, "unknown, r4");
	cr_expect(is_line_valid(line) == -1);
	set_line(line, "ld, 456, r17 ");
	cr_expect(is_line_valid(line) == -1);
}
