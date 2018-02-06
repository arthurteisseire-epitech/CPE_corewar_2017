/*
** EPITECH PROJECT, 2017
** my_put_error.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int my_put_error(char const *str)
{
	write(2, str, my_strlen(str));
	return (0);
}
