/*
** EPITECH PROJECT, 2017
** File Name : test_get_value_token.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "parse.h"
#include "op.h"
#include "buffer.h"
#include "line.h"
#include "token.h"

Test(set_token_value, get_value)
{
	buffer_t buffer;

	my_asm(&buffer, "get_token_value.s");
	cr_assert(buffer.lines[0].tokens[1].value == 14);
	cr_assert(buffer.lines[0].tokens[2].value == 2);
	cr_assert(buffer.lines[0].tokens[3].value == 1);
	cr_assert(buffer.lines[1].tokens[1].value == 53);
	cr_assert(buffer.lines[1].tokens[2].value == 10);
}
