/*
** EPITECH PROJECT, 2017
** File Name : set_buffer_bytes.c
** File description:
** by Arthur Teisseire
*/

#include "asm.h"
#include "buffer.h"
#include "line.h"

void set_buffer_bytes(buffer_t *buffer)
{
	buffer->nb_bytes = 0;
	for (int i = 0; i < buffer->nb_lines; i++)
		buffer->nb_bytes += buffer->lines[i].nb_bytes;
}
