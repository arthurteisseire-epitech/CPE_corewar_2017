/*
** EPITECH PROJECT, 2017
** File Name : buffer.h
** File description:
** by Arthur Teisseire
*/

#ifndef BUFFER_H
#define BUFFER_H

typedef struct line line_t;

typedef struct label {
	char *label;
	int line;
} label_t;

typedef struct buffer {
	line_t *line;
	label_t *label;
	int curr_byte;
	int nb_lines;
} buffer_t;

void init_buffer(buffer_t *buffer);

#endif
