/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** Rémi BISSON
*/
#include "my.h"

int my_putchar(char c)
{
	write(1, &c, 1);
}
