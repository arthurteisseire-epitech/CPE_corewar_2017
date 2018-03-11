/*
** EPITECH PROJECT, 2017
** File Name : token.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOKEN_H
#define TOKEN_H

typedef struct line line_t;

typedef union bin {
	int dir;
	short int ind;
	char reg;
} bin_u;

typedef struct token {
	char *str;
	int cbyte;
	int nb_bytes;
	int is_label;
	bin_u value;
	char binary[4];
} token_t;

int set_tokens(line_t *line, char **tokens);
int init_tokens(line_t *line, char **tokens);
int set_token(line_t *line, int i);
void set_token_bytes(line_t *line, token_t *token);

#endif
