/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** LIB
*/

#include "my.h"

int my_char_is_alpha_num(char c)
{
	if (my_char_is_num(c) == 0 && my_char_is_alpha(c) == 0)
		return (0);
	else
		return (1);
}