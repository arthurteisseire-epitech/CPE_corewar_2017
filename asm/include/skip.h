/*
** EPITECH PROJECT, 2017
** File Name : skip.h
** File description:
** by Arthur Teisseire
*/

#ifndef SKIP_H
#define SKIP_H

typedef struct buffer buffer_t;

int skip_comments_and_labels(buffer_t *buffer, char **line, int index_line);
int is_label(char *line);
int is_label_valid(char *line, char const *sep);
int is_comment(char *line, char const *sep);
int skip_comments(int fd, char **line, char const *sep);

int store_label(buffer_t *buffer, char *label, int index_line);
int set_new_line(buffer_t *buffer, char **line, char *end, char *label);
int set_label_line(buffer_t *buffer, char **line, char const *sep,
	int index_line);
int skip_and_set_labels(buffer_t *buffer, char **line, char const *sep,
	int index_line);

#endif
