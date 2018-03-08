/*
** EPITECH PROJECT, 2017
** File Name : test_is_index.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "asm.h"
#include "parse.h"
#include "op.h"
#include "line.h"
#include "token.h"

Test(is_index, True)
{
	line_t line;
	token_t token;

	line.tokens = &token;
	token.str = my_strdup("live");
	cr_assert(is_index(&line) == 1);
	token.str = my_strdup("zjmp");
	cr_assert(is_index(&line) == 1);
	token.str = my_strdup("sti");
	cr_assert(is_index(&line) == 1);
	token.str = my_strdup("ldi");
	cr_assert(is_index(&line) == 1);
	token.str = my_strdup("fork");
	cr_assert(is_index(&line) == 1);
	token.str = my_strdup("lfork");
	cr_assert(is_index(&line) == 1);
	token.str = my_strdup("lldi");
	cr_assert(is_index(&line) == 1);
}

Test(is_index, False1)
{
	line_t line;
	token_t token;

	line.tokens = &token;
	token.str = my_strdup("ld");
	cr_assert(is_index(&line) == 0);
	token.str = my_strdup("st");
	cr_assert(is_index(&line) == 0);
	token.str = my_strdup("add");
	cr_assert(is_index(&line) == 0);
	token.str = my_strdup("sub");
	cr_assert(is_index(&line) == 0);
}

Test(is_index, False2)
{
	line_t line;
	token_t token;

	line.tokens = &token;
	token.str = my_strdup("and");
	cr_assert(is_index(&line) == 0);
	token.str = my_strdup("or");
	cr_assert(is_index(&line) == 0);
	token.str = my_strdup("xor");
	cr_assert(is_index(&line) == 0);
	token.str = my_strdup("lld");
	cr_assert(is_index(&line) == 0);
	token.str = my_strdup("aff");
	cr_assert(is_index(&line) == 0);
}
