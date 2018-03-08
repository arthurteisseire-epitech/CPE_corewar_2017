/*
** EPITECH PROJECT, 2017
** File Name : free.h
** File description:
** Rémi BISSON 
*/
#ifndef FREE_H
#define FREE_H

#include <stdlib.h>

int free_token(token_t *token);
int free_line(line_t *line);
int free_label(label_t *label);
int free_buffer(buffer_t *buffer);

#endif
