/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** manage header
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

int nb_char_in_str(char c, char *str)
{
	int i = 0;
	int occ = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			occ++;
		i++;
	}
	return (occ);
}

static char **split_header(char *str, char *sep)
{
	char **arr = malloc(sizeof(char *) * (3 + 1));
	char *tmp;

	if (arr == NULL)
		return (NULL);
	arr[0] = get_next_word(&str, sep);
	arr[1] = get_next_word(&str, "\"");
	tmp =  get_next_word(&str, sep);
	arr[2] = tmp;
	arr[3] = NULL;
	if (arr[2][0] == '\0') {
		free(tmp);
		arr[2] = NULL;
		free(arr[3]);
	}
	return(arr);
}

static int check_header(char *name, char *comment)
{
	char **name_arr = split_header(name, separators);
	char **comment_arr;

	if (comment == NULL) {
		put_err_asm(SYNTAX_ERROR);
		return (-1);
	}
	comment_arr = split(comment, separators);
	if (((my_strcmp(name_arr[0], NAME_CMD_STRING) != 0 && my_strcmp(name_arr[0], COMMENT_CMD_STRING) != 0) && get_id_cmd(name_arr[0]) == -1)) {
		put_err_asm(INVALID_INSTRUCTION);
		return (-1);
	}
	if (((my_strcmp(comment_arr[0], COMMENT_CMD_STRING) != 0 && my_strcmp(comment_arr[0], NAME_CMD_STRING) != 0) && get_id_cmd(comment_arr[0]) == -1)) {
		true_index(1);
		put_err_asm(INVALID_INSTRUCTION);
		return (-1);
	}
	if (my_strcmp(name_arr[0], NAME_CMD_STRING) != 0 && my_strcmp(comment_arr[0], COMMENT_CMD_STRING) == 0) {
		put_err_asm(MISPLACED_NAME);
		return (-1);
	}
	if (my_strcmp(name_arr[0], NAME_CMD_STRING) == 0 && my_strcmp(comment_arr[0], COMMENT_CMD_STRING) != 0) {
		put_err_asm(NO_COMMENT_W);
		return (-1);
	}
	if (my_strcmp(name_arr[0], COMMENT_CMD_STRING) == 0 && my_strcmp(comment_arr[0], NAME_CMD_STRING) == 0) {
		put_err_asm(MISPLACED_COMMENT);
		return (-1);
	}
	if (my_arrlen(name_arr) > 2 || nb_char_in_str('\"', name) != 2) {
		put_err_asm(SYNTAX_ERROR);
		return (-1);
	}
	if (my_arrlen(comment_arr) > 2  || nb_char_in_str('\"', comment) != 2) {
		true_index(1);
		put_err_asm(SYNTAX_ERROR);
		return (-1);
	}
	if (my_arrlen(name_arr) == 1) {
		put_err_asm(NO_NAME);
		return (-1);
	}
	if (my_arrlen(comment_arr) == 1) {
		put_err_asm(EMPTY_COMMENT);
		return (-1);
	}
	return (0);
}

static int set_comment_and_name(char *name, char *comment, header_t *header)
{
	char **name_cpy = split_header(name, separators);
	char **comment_cpy = split_header(comment, separators);

	my_strcpy(header->prog_name, name_cpy[1]);
	my_strcpy(header->comment, comment_cpy[1]);
	header->magic = COREWAR_EXEC_MAGIC;
	free_array(name_cpy);
	free_array(comment_cpy);
	return (0);
}

int set_header(header_t *header, int fd)
{
	char *name = get_next_line(fd);
	char *comment = get_next_line(fd);
//decaler l'initalisation et boucler jusqu'a tant que ca soit plus un commentaire avant la vrai init et effacer a name et a comment le #
	true_index(1);
	if (name == NULL) {
		put_or_init_err(NULL, 0);
		my_puterror(" :");
		my_puterror(EMPTY_FILE);
		my_puterror("\n");
		return (-1);
	}
	if (check_header(name, comment) == -1)
		return (-1);
	set_comment_and_name(name, comment, header);
	free(name);
	free(comment);
	true_index(1);
	return (0);
}
