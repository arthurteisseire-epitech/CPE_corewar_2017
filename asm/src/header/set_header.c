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
#include "header.h"

int set_comment_and_name(char *name, char *comment, header_t *header)
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

int free_name_and_comment(char *name, char *comment)
{
	free(name);
	free(comment);
	return (0);
}

int print_error_and_free(char *name, char *comment)
{
	put_or_init_err(NULL, 0);
	my_puterror(" :");
	my_puterror(EMPTY_FILE);
	my_puterror("\n");
	free_name_and_comment(name, comment);
	return (0);
}

int set_header2(char *name, char *comment, int index_name, header_t *header)
{
	name = my_clean_str(name, '\t');
	name = my_clean_str(name, ' ');
	if (comment != NULL) {
		comment = my_clean_str(comment, ' ');
		comment = my_clean_str(comment, '\t');
	}
	if (check_header(name, comment, index_name) == -1) {
		free_name_and_comment(name, comment);
		return (-1);
	}
	set_comment_and_name(name, comment, header);
	free_name_and_comment(name, comment);
	return (0);
}

int set_header1(header_t *header, int fd)
{
	char *name = get_next_line(fd);
	char *comment;
	int index_name = 0;

	true_index(1);
	for (int i = 0; i < PROG_NAME_LENGTH + 4; i++)
		header->prog_name[i] = '\0';
	for (int i = 0; i < COMMENT_LENGTH + 4; i++)
		header->comment[i] = '\0';
	skip_comments(fd, &name, separators);
	index_name = true_index(0);
	comment = get_next_line(fd);
	true_index(1);
	if (comment == NULL) {
		put_err_asm(SYNTAX_ERROR);
		return (-1);
	}
	skip_comments(fd, &comment, separators);
	if (name == NULL) {
		print_error_and_free(name, comment);
		return (-1);
	}
	if (set_header2(name, comment, index_name, header) == -1) {
		return (-1);
	}
	return (0);
}
