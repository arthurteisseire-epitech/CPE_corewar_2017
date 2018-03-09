/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** put asm err
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

void put_or_init_err(char **av_init, int index_arg)
{
	static char **av;
	static int index;

	if (av_init != NULL) {
		av = av_init;
		av[0] = get_next_word(&av[0], "./");
		index = index_arg;
	} else {
		my_puterror(av[0]);
		my_puterror(", ");
		my_puterror(av[index]);
		my_puterror(", ");
	}
}

int true_index(int i)
{
	static int index;

	index += i;
	return (index);
}

void put_err_asm(char *error)
{
	char *nb_line = my_itoa(true_index(0));

	put_or_init_err(NULL, 0);
	my_puterror("line ");
	my_puterror(nb_line);
	free(nb_line);
	my_puterror(": ");
	my_puterror(error);
	my_puterror("\n");
}
