/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** my str is alpha num
*/

#include "my.h"

int my_str_is_alpha_num(char *str)
{
	int i = 0;

	while (my_char_is_alpha_num(str[i]) == 1 || (str[i] == '\0')) {
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
