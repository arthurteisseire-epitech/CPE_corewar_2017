/*
** EPITECH PROJECT, 2017
** File Name : check_header2.c
** File description:
** Rémi BISSON
*/

#include <stdlib.h>
#include "parse.h"
#include "buffer.h"
#include "my.h"
#include "op.h"
#include "line.h"
#include "asm.h"
#include "errors.h"
#include "token.h"
#include "header.h"

int check_name_syntax_error(char **name_arr, char *name)
{
	if (my_arrlen(name_arr) > 2 || (nb_char_in_str('\"', name) != 2
		&& my_arrlen(name_arr) == 2)) {
		true_index(-1);
		put_err_asm(true_index(0), SYNTAX_ERROR);
		return (-1);
	}
	return (0);
}

int check_comment_syntax_error(char **comment_arr, char *comment)
{
	if (my_arrlen(comment_arr) > 2  || (nb_char_in_str('\"', comment) != 2
		&& my_arrlen(comment_arr) == 2)) {
		put_err_asm(true_index(0), SYNTAX_ERROR);
		return (-1);
	}
	return (0);
}

int check_name(char **name_arr)
{
	if (my_arrlen(name_arr) == 1) {
		true_index(-1);
		put_err_asm(true_index(0), NO_NAME);
		return (-1);
	}
	return (0);
}

int check_empty_comment(char **comment_arr)
{
	if (my_arrlen(comment_arr) == 1) {
		put_err_asm(true_index(0), EMPTY_COMMENT);
		return (-1);
	}
	return (0);
}

int check_header(char *name, char *comment, int index_name)
{
	char **name_arr = split_header(name, separators);
	char **comment_arr = split_header(comment, separators);

	if (check_invalid_name_instruction(name_arr, index_name) == -1
		|| check_invalid_comment_instruction(comment_arr) == -1
		|| check_misplaced_name(name_arr, comment_arr, index_name) == -1
		|| check_no_comment_w(name_arr, comment_arr, index_name) == -1
		|| check_misplaced_comment(name_arr,
			comment_arr, index_name) == -1
		|| check_name_syntax_error(name_arr, name) == -1
		|| check_comment_syntax_error(comment_arr, comment) == -1
		|| check_name(name_arr) == -1
		|| check_empty_comment(comment_arr) == -1)
		return (-1);
	return (0);
}
