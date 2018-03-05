/*
** EPITECH PROJECT, 2017
** File Name : asm.h
** File description:
** by Arthur Teisseire
*/

#ifndef ASM_H
#define ASM_H

typedef struct label {
	char *label;
	int line;
} label_t;

typedef struct token {
	int type;
	char *str;
} token_t;

typedef struct line {
	token_t *token;
	int size;
	char label;
	int nb_bytes;	
} line_t;

typedef struct buffer {
	line_t *line;
	label_t *label;
	int curr_byte;
} buffer_t;

#endif
