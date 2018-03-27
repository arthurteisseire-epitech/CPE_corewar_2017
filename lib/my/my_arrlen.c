/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** LIB
*/

#include <stdlib.h>

int my_arrlen(char **array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;
	return (i);
}
