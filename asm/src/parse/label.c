/*
** EPITECH PROJECT, 2017
** File Name : label.c
** File description:
** Ozz
*/

#include "op.h"
#include "my.h"

int is_label(char *line)
{
	int i = 0;

	while (is_char_in_str(line[i], LABEL_CHARS))
		i++;
	if (line[i] == LABEL_CHAR && line[i + 1] == '\0')
		return (1);
	return (0);
} 

int is_label_call(char *line)
{
	int i = 2;

	if (line[0] == '%' && line[1] == LABEL_CHAR) {
		while (is_char_in_str(line[i], LABEL_CHARS))
			i++;
		if (line[i] == '\0')
			return (1);
	}
	return (0);
}
