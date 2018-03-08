/*
** EPITECH PROJECT, 2017
** File Name : init_tokens.c
** File description:
** by Arthur Teisseire
*/

#include "asm.h"
#include "line.h"
#include "token.h"

void init_token(token_t *token)
{
	token->is_label = 0;
	token->cbyte = 0;
	token->nb_bytes = 0;
}
