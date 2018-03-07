/*
** EPITECH PROJECT, 2017
** File Name : token.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOKEN_H
#define TOKEN_H

typedef struct line line_t;

typedef struct token {
	char *str;
	int type;
	int cbyte;
	int nb_bytes;
} token_t;

void set_token_bytes(line_t *line, token_t *token);
int set_tokens(line_t *line, char **tokens);

#endif
