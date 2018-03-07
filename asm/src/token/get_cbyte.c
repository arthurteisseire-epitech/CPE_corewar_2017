/*
** EPITECH PROJECT, 2017
** File Name : get_cbyte.c
** File description:
** by Arthur Teisseire
*/

#include "asm.h"

static char const type[] = {REG_CHAR, DIRECT_CHAR, '\0'};

int token_cbyte(token_t *token)
{
	int i = 0;

	while (type[i] != '\0') {
		if (token->str[0] == type[i])
			return (i + 1);
		i++;
	}
	return (i + 1);
}
