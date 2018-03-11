/*
** EPITECH PROJECT, 2017
** File Name : skip_and_set_labels.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "asm.h"
#include "errors.h"
#include "buffer.h"
#include "skip.h"

int store_label(buffer_t *buffer, char *label)
{
	buffer->nb_labels += 1;
	buffer->labels = realloc(buffer->labels, sizeof(label_t) * buffer->nb_labels);
	buffer->labels[buffer->nb_labels - 1].str = label;
	if (buffer->labels == NULL)
		return (-1);
	return (0);
}

int set_new_line(buffer_t *buffer, char **line, char **tokens)
{
	char *tmp_line = *line;

	if (tokens[1] == NULL) {
		*line = get_next_line(buffer->fd);
		true_index(1);
		free_array(tokens);
		if (*line == NULL)
			return (-1);
	} else {
		*line = tokens[1];
		free(tokens[0]);
		free(tokens);
	}
	free(tmp_line);
	return (0);
}

int set_label_line(buffer_t *buffer, char **line, char const *sep)
{
	static char const sep_lab[2] = {LABEL_CHAR, '\0'};
	char **tokens = split(*line, sep_lab);
	char *first_token = tokens[0];
	char *label;

	if (tokens == NULL)
		return (-1);
	label = get_next_word(&first_token, sep);
	if (label == NULL)
		return (-1);
	if (store_label(buffer, label) == -1)
		return (-1);
	if (set_new_line(buffer, line, tokens) == -1)
		return (-1);
	return (0);
}

int skip_and_set_labels(buffer_t *buffer, char **line, char const *sep)
{
	int lab_char;
	
	if (*line == NULL)
		return (0);
	lab_char = is_label_valid(*line, sep);
	if (lab_char == -1) {
		put_err_asm(INVALID_LABEL);
		return (-1);
	} else if (lab_char == 0)
		return (0);
	if (set_label_line(buffer, line, sep) == -1)
		return (-1);
	return (1);
}

/*
#include <fcntl.h>
int main(int ac, char **av)
{
	char *line;
	buffer_t buffer;

	if (ac != 2)
		return (84);
	buffer.labels = NULL;
	buffer.nb_labels = 0;
	buffer.fd = open(av[1], O_RDONLY);
	line = get_next_line(buffer.fd);
	if (line == NULL)
		return (84);
	printf("BEFORE: %s\n", line);
	skip_and_set_labels(&buffer, &line, " \t");
	printf("AFTER: %s\n", line);
	printf("LABELS IN BUFFER: \n");
	for (int i = 0; i < buffer.nb_labels; i++) {
		printf("LABEL[%d] : %s\n", i, buffer.labels[i].str);
		free(buffer.labels[i].str);
	}
	free(buffer.labels);
	free(line);
	close(buffer.fd);
	return (0);
}
*/
