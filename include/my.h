/*
** EPITECH PROJECT, 2017
** LIB
** File description:
** lib.h
*/

#ifndef MY_H_
#define	MY_H_
#include <stdlib.h>

void 		my_putchar(char);
int 		my_strlen(char *);
int			my_putstr(char *);
int 		my_puterr(char *);
int   		my_get_nbr(char *);
void 		free_array(char **);
void 		my_show_array(char **);
int    		my_putnbr(int);
char *		itos(int);
int 		stoi(char *);
char *  	my_strdup(char *);
char *		my_strcat(char *, char *);
int 		my_char_is_alpha_num(char);
int 		my_char_is_alpha(char);
int 		my_char_is_num(char);
int 		my_strcmp(char const *, char const *);
int			my_strncmp(char const *, char const *, int);
int 		is_in_str(char *str, char);
char **		my_strtab(char *, char *);
char * 		my_strnlcpy(char *, int);
char **		my_arrcpy(char **);
int 		my_is_printable(char);
char *		my_clean_str(char *);
int 		my_str_is_num(char *);
int 		my_str_is_alpha_num(char *);

#endif