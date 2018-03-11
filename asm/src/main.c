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
#include "free.h"
#include "errors.h"

char const separators[3] = {SEPARATOR_CHAR, ' ', '\t'};

static int check_args(int ac)
{
	if (ac == 1) {
		my_puterror("Usage: ./asm file_name[.s] ....\n");
		return (-1);
	}
	return (0);
}

int main(int ac, char **av)
{
	int status;

	if (check_args(ac) == -1)
		return (84);
	for (int i = 1; i < ac; i++) {
		put_or_init_err(av, i);
		status = my_asm(av[i]);
	}
	if (status == FEND)
		return (0);
	else if (status == -1)
		return (84);
	return (status);
}
