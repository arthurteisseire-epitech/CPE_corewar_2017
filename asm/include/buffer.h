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
	char *str;
	int line;
} label_t;

typedef struct buffer {
	line_t *lines;
	label_t *labels;
	int nb_lines;
	int nb_bytes;
	int nb_labels;
	int curr_byte;
	int fd;
	char *binary;
} buffer_t;

int init_buffer(buffer_t *buffer, char *pathname);
void set_buffer_bytes(buffer_t *buffer);
int true_index(int i);

#endif
