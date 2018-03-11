/*
** EPITECH PROJECT, 2017
** File Name : header.h
** File description:
** Rémi BISSON 
*/
#ifndef HEADER_H
#define HEADER_H

int free_name_and_comment(char *name, char *comment);
int print_error_and_free(char *name, char *comment);
int set_comment_and_name(char *name, char *comment, header_t *header);
int set_header2(char *name, char *comment, int index_name, header_t *header);
int set_header1(header_t *header, int fd);
char **split_header(char *str, char const *sep);
int check_invalid_name_instruction(char **name_arr, int index_name);
int check_invalid_comment_instruction(char **comment_arr);
int check_misplaced_name(char **name_arr, char **comment_arr, int index_name);
int check_no_comment_w(char **name_arr, char **comment_arr, int index_name);
int check_misplaced_comment(char **name_arr, char **comment_arr,
						int index_name);
int check_name_syntax_error(char **name_arr, char *name, int index_name);
int check_comment_syntax_error(char **comment_arr, char *comment);
int check_name(char **name_arr, int index_name);
int check_empty_comment(char **comment_arr);
int check_header(char *name, char *comment, int index_name);

#endif
