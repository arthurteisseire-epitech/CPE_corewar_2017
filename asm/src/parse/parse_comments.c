/*
** EPITECH PROJECT, 2017
** File Name : parse_comments.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

int skip_comments(int fd, char **line, char *separators)
{
	if (*line == NULL)
		return (FEND);
	while (is_comment(*line, separators)) {
		if (*line == NULL)
			return (FEND);
		free(*line);
		*line = get_next_line(fd);
	}
	return (0);
}

int is_comment(char *line, char *separators)
{
	int i = 0;

	while (is_char_in_str(line[i], separators))
		i++;
	if (line[i] == '#')
		return (1);
	return (0);
}
