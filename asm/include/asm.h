/*
** EPITECH PROJECT, 2017
** File Name : asm.h
** File description:
** by Arthur Teisseire
*/

#ifndef ASM_H
#define ASM_H

#define FEND 42
#define NB_CBYTE 12
#define NB_INDEX 7
#define REG_CHAR 'r'
#define REV_BYTES(num)	((num & 0xff000000) >> 24) + \
			((num & 0x00ff0000) >> 8) + \
			((num & 0x0000ff00) << 8) + \
			((num & 0x000000ff) << 24)

typedef struct buffer buffer_t;

int my_asm(char *pathname);
int set_buffer(buffer_t *buffer);
int set_binary(buffer_t *buffer);
int write_binary(buffer_t *buffer);

extern char const separators[3];

#endif
