/*
** EPITECH PROJECT, 2017
** LIB
** File description:
** free char **
*/

#include <stdlib.h>

void free_array(char **arr)
{
	int i = 0;

	while (arr[i] != NULL) {
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}