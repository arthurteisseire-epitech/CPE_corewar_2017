/*
** EPITECH PROJECT, 2017
** File Name : my_getnbr.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int my_getnbr(char const *str)
{
	int nb = 0;
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (str[i] < '0' && str[i] > '9')
			i++;
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		nb = nb * -1;
	return (nb);
}
