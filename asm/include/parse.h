/*
** EPITECH PROJECT, 2017
** File Name : parse.h
** File description:
** Ozz
*/
#ifndef PARSE_H
#define PARSE_H

typedef struct op_s op_t;
typedef struct line line_t;

int is_opt_end(op_t *opt);
int get_id_cmd(char *cmd);
int skip_comments(int fd, char **line, char const *sep);
int is_comment(char *line, char const *sep);
int is_line_valid(line_t *line);

int skip_and_set_labels(buffer_t *buffer, char **line, char const *sep);
int set_label_line(buffer_t *buffer, char **line, char const *sep);
int set_new_line(buffer_t *buffer, char **line, char **tokens);
int store_label(buffer_t *buffer, char *label);
int is_label(char *line);
int is_label_valid(char *line, char const *sep);

#endif
