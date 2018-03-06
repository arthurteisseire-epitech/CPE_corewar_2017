/*
** EPITECH PROJECT, 2017
** File Name : parse.h
** File description:
** Ozz
*/
#ifndef PARSE_H
#define PARSE_H

typedef struct op_s op_t;

int is_opt_end(op_t opt);
int get_id_cmd(op_t *op_tab, char *cmd);

#endif
