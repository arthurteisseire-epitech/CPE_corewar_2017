/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** Rémi BISSON
*/

#include "op.h"
#include "my.h"
#include "asm.h"
#include "buffer.h"
#include "line.h"
#include "token.h"

char const separators[3] = {SEPARATOR_CHAR, ' ', 't'};

static int check_args(int ac)
{
	if (ac == 1) {
		my_puterror("Usage: ./asm file_name[.s] ....\n");
		return (-1);
	}
	return (0);
}

#include <stdio.h>
static void print_tokens(buffer_t *buffer)
{
	int i = 0;
	int j = 0;
	line_t *line;

	while (i < buffer->nb_lines) {
		j = 0;
		line = &buffer->lines[i];
		while (j < line->nb_tokens) {
			printf("LINE[%d] -> TOKEN[%d] : %s\n", i, j, line->tokens[j].str);
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int status;
	buffer_t buffer;

	if (check_args(ac) == -1)
		return (84);
	for (int i = 1; i < ac; i++)
		status = my_asm(&buffer, av[i]);
	if (status != -1) {
		print_tokens(&buffer);
		printf("NB_BYTES: %d\n", buffer.nb_bytes);
	}
	if (status == FEND)
		return (0);
	return (status);
}
