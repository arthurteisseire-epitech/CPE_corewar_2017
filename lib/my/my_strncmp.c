/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** my_strncmp
*/

#include <stdlib.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i != n) {
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}