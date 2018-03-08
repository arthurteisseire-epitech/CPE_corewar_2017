/*
** EPITECH PROJECT, 2017
** File Name : free.c
** File description:
** Rémi BISSON 
*/
#include "line.h"
#include "buffer.h"
#include "free.h"
#include "token.h"

int free_token(token_t *token)
{
	if (token->str != NULL) {
		free(token->str);
	}
	return (0);
}

int free_line(line_t *line)
{
	if (line != NULL) {
		for (int i = 0; i + 1 < line->nb_tokens; i++)
			free_token(&line->tokens[i]);
		free(line->tokens);
	}
	return (0);
}

int free_label(label_t *label)
{
	if (label != NULL) {
		if (label->str != NULL)
			free(label->str);
	}
	return (0);
}

int free_buffer(buffer_t *buffer)
{
	if (buffer != NULL) {
		for (int i = 0; i < buffer->nb_lines; i++) {
			free_line(&buffer->lines[i]);
		}
		free(buffer->lines);
		for (int i = 0; i < buffer->nb_labels; i++)
			free_label(&buffer->labels[i]);
		free(buffer->labels);
	}
	return (0);
}
