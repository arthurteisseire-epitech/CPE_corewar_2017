/*
** EPITECH PROJECT, 2017
** File Name : check_label.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "skip.h"

int is_label(char *line)
{
	int i = 0;

	while (line[i] != '\0') {
		if (line[i] == LABEL_CHAR) {
			if (i != 0 && line[i - 1] == DIRECT_CHAR)
				return (0);
			return (i);
		}
		i++;
	}
	return (0);
}

int is_label_valid(char *line, char const *sep)
{
	int i = 0;
	int lab_char = is_label(line);
	char *label = get_next_word(&line, sep);

	if (label == NULL)
		return (-1);
	if (!lab_char) {
		free(label);
		return (0);
	}
	while (label[i] != LABEL_CHAR) {
		if (!is_char_in_str(label[i], LABEL_CHARS)) {
			free(label);
			return (-1);
		}
		i++;
	}
	free(label);
	return (lab_char);
}
