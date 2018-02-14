/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** str to word array
*/

#include "my.h"
#include <stdlib.h>

static int next_word(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

static int count_word(char *str)
{
	int i = 0;
	int word = 0;

	while (str[i] != '\0') {
		if (str[i] == ' ') {
			word++;
			i = next_word(str, i);
		}
		else
			i++;
	}
	return (word);
}

static char *remove_char(char *str, char delim)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == delim) {
			str[i] = ' ';
		}
		i++;
	}
	return (str);
}

static char **str_in_array(char **array, char *str, int word)
{
	int size = 0;
	int i = 0;
	int k = 0;

	for (int j = 0; j != word; j++) {
		while (str[size] != ' ' && str[size] != '\0')
			size++;
		array[j] = malloc(sizeof(char) * size + 1);
		while (k != size) {
			array[j][i] = str[k];
			i++;
			k++;
		}
		array[j][i] = '\0';
		k++;
		size = next_word(str, size);
		i = 0;
	}
	return (array);
}

char **my_strtab(char *base, char *delim)
{
	char *str_base = my_strdup(base);
	char *str;
	int i = 0;
	int word = 0;
	char **array;

	while (delim[i] != '\0') {
		str_base = remove_char(str_base, delim[i]);
		i++;
	}
	str = my_clean_str(str_base);
	free(str_base);
	word = count_word(str) + 1;
	array = malloc(sizeof(char *) * (word + 1));
	if (array == NULL)
		return (NULL);
	array[word] = NULL;
	array = str_in_array(array, str, word);
	free(str);
	return (array);
}