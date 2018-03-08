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
	int cbyte;
	int nb_bytes;
	int is_label;
} token_t;

int set_tokens(buffer_t *buffer, line_t *line, char **tokens);
int init_tokens(buffer_t *buffer, line_t *line, char **tokens);
int set_token(line_t *line, int i);
void set_token_bytes(line_t *line, token_t *token);

#endif
