/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** cpy an array
*/

#include "my.h"
#include <stdlib.h>

char **my_arrcpy(char **array)
{
	char **arr;
	int i = 0;

	while (array[i] != NULL)
		i++;
	arr = malloc(sizeof(char *) * (i + 1));
	if (arr == NULL)
		return (NULL);
	arr[i] = NULL;
	i = 0;
	while (array[i] != NULL) {
		arr[i] = my_strdup(array[i]);
		i++;
	}
	return (arr);
}