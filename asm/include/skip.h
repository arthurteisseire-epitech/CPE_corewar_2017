/*
** EPITECH PROJECT, 2017
** File Name : skip.h
** File description:
** by Arthur Teisseire
*/

#ifndef SKIP_H
#define SKIP_H

typedef struct buffer buffer_t;

int skip_comments_and_labels(buffer_t *buffer, char **line);
int skip_and_set_labels(buffer_t *buffer, char **line, char const *sep);
int set_label_line(buffer_t *buffer, char **line, char const *sep);
int set_new_line(buffer_t *buffer, char **line, char **tokens);
int store_label(buffer_t *buffer, char *label);
int is_label(char *line);
int is_label_valid(char *line, char const *sep);
int is_comment(char *line, char const *sep);
int skip_comments(int fd, char **line, char const *sep);

#endif
