/*
** EPITECH PROJECT, 2017
** File Name : check_header1.c
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

int check_invalid_name_instruction(char **name_arr, int index_name)
{
	if (((my_strcmp(name_arr[0], NAME_CMD_STRING) != 0
		&& my_strcmp(name_arr[0], COMMENT_CMD_STRING) != 0)
		&& get_id_cmd(name_arr[0]) == -1)) {
		true_index(-1);
		true_index(index_name);
		put_err_asm(INVALID_INSTRUCTION);
		return (-1);
	}
	return (0);
}

int check_invalid_comment_instruction(char **comment_arr)
{
	if (((my_strcmp(comment_arr[0], COMMENT_CMD_STRING) != 0
		&& my_strcmp(comment_arr[0], NAME_CMD_STRING) != 0)
		&& get_id_cmd(comment_arr[0]) == -1)) {
		put_err_asm(INVALID_INSTRUCTION);
		return (-1);
	}
	return (0);
}

int check_misplaced_name(char **name_arr, char **comment_arr, int index_name)
{
	if (my_strcmp(name_arr[0], NAME_CMD_STRING) != 0
		&& my_strcmp(comment_arr[0], COMMENT_CMD_STRING) == 0) {
		true_index(-1);
		true_index(index_name);
		put_err_asm(MISPLACED_NAME);
		return (-1);
	}
	return (0);
}

int check_no_comment_w(char **name_arr, char **comment_arr, int index_name)
{
	if (my_strcmp(name_arr[0], NAME_CMD_STRING) == 0
		&& my_strcmp(comment_arr[0], COMMENT_CMD_STRING) != 0) {
		true_index(-1);
		true_index(index_name);
		put_err_asm(NO_COMMENT_W);
		return (-1);
	}
	return (0);
}

int check_misplaced_comment(char **name_arr, char **comment_arr,
int index_name)
{
	if (my_strcmp(name_arr[0], COMMENT_CMD_STRING) == 0
		&& my_strcmp(comment_arr[0], NAME_CMD_STRING) == 0) {
		true_index(-1);
		true_index(index_name);
		put_err_asm(MISPLACED_COMMENT);
		return (-1);
	}
	return (0);
}
