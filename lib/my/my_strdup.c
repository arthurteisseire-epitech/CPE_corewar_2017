/*
** EPITECH PROJECT, 2017
** LIB
** File description:
** stdup for lib
*/

#include "my.h"

char *my_strdup(char *str)
{
	char *copy = malloc(sizeof(char) * my_strlen(str) + 1);
	int i = 0;

	if (copy == NULL)
		return (NULL);
	while (str[i] != '\0') {
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}