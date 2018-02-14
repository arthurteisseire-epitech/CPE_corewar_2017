/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** LIB
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *str, char *buffer)
{
	int i = 0;
	int j = 0;
	int size = my_strlen(str) + my_strlen(buffer) + 1;
	char *str_catd = malloc(sizeof(char) * size);

	if (str_catd == NULL)
		return (str);
	while (str[i] != '\0') {
		str_catd[i] = str[i];
		i++;
	}
	while (buffer[j] != '\0') {
		str_catd[i] = buffer[j];
		j++;
		i++;
	}
	str_catd[i] = '\0';
	free(str);
	free(buffer);
	return (str_catd);
}
