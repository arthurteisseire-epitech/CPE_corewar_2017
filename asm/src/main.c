/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** Rémi BISSON
*/

#include "my.h"
#include "asm.h"

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
	buffer_t buffer;

	if (check_args(ac) == -1)
		return (84);
	for (int i = 1; i < ac; i++)
		status = my_asm(&buffer, av[i]);
	return (status);
}
