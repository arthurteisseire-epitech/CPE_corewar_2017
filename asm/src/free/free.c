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
		if (line->tokens != NULL)
			free(line->tokens);
		if (line->binary != NULL)
			free(line->binary);
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
	for (int i = 0; i < buffer->nb_lines; i++) {
		free_line(&buffer->lines[i]);
	}
	if (buffer->lines != NULL)
		free(buffer->lines);
	for (int i = 0; i < buffer->nb_labels; i++)
		free_label(&buffer->labels[i]);
	if (buffer->labels != NULL)
		free(buffer->labels);
	if (buffer->cor_name != NULL)
		free(buffer->cor_name);
	/*if (buffer->binary != NULL)
	  free(buffer->binary);*/
	return (0);
}
