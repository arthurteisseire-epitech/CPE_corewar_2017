/*
** EPITECH PROJECT, 2017
** File Name : my_putnbr.c
** File description:
** Rémi BISSON
*/
#include "my.h"

void my_putnbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 0 && nb <= 9) {
		my_putchar(nb + '0');
	}
	if (nb > 9) {
		my_putnbr(nb / 10);
		my_putnbr(nb % 10);
	}
}
