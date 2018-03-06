/*
** EPITECH PROJECT, 2017
** File Name : parse_comments.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "asm.h"

int skip_comments(int fd, char **line, char *sep)
{
	char const comment_char[2] = {COMMENT_CHAR, '\0'};
	char *new_line;

	while (*line != NULL) {
		if (!is_comment(*line, sep)) {
			new_line = get_next_word(line, comment_char);
			//free(*line);
			*line = new_line;
			return (0);
		}
		free(*line);
		*line = get_next_line(fd);
	}
	return (FEND);
}

int is_comment(char *line, char *sep)
{
	int i = 0;

	while (is_char_in_str(line[i], sep))
		i++;
	if (line[i] == COMMENT_CHAR || line[i] == '\0')
		return (1);
	return (0);
}
