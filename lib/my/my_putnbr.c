/*
** EPITECH PROJECT, 2017
** EvalExpr
** File description:
** CPool
*/

#include "my.h"

int my_putnbr(int nb)
{
	int mod = 0;
	int res = 0;
	int cmpt = 0;

	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	} if (nb >= 0) {
		cmpt++;
		if (nb >= 10) {
			mod = nb % 10;
			res = (nb - mod) / 10;
			my_putnbr(res);
			my_putchar(mod + '0');
		} else
			my_putchar(nb % 10 + '0');
	}
	return (cmpt);
}
