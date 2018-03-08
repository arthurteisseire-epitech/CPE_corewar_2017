/*
** EPITECH PROJECT, 2017
** File Name : set_token_bytes.c
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

Test(set_token_byte, direct_value)
{
	line_t line;
	token_t token;

	token.str = my_strdup("%18");
	line.is_index = 0;
	set_token_bytes(&line, &token);
	cr_assert(token.nb_bytes == 4);
}

Test(set_token_byte, indirect_value)
{
	line_t line;
	token_t token;

	token.str = my_strdup("18");
	line.is_index = 0;
	set_token_bytes(&line, &token);
	cr_assert(token.nb_bytes == 2);
}

Test(set_token_byte, reg_value)
{
	line_t line;
	token_t token;

	token.str = my_strdup("r8");
	line.is_index = 0;
	set_token_bytes(&line, &token);
	cr_assert(token.nb_bytes == 1);
}

Test(set_token_byte, index)
{
	line_t line;
	token_t token;

	token.str = my_strdup("%17");
	line.is_index = 1;
	set_token_bytes(&line, &token);
	cr_assert(token.nb_bytes == 2);
}
