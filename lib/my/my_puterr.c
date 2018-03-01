/*
** EPITECH PROJECT, 2017
** EvalExpr
** File description:
** CPool
*/

#include "my.h"
#include <unistd.h>

int my_puterr(char *str)
{
	int i = my_strlen(str);

	write(2, str, i);
	return (i);
}