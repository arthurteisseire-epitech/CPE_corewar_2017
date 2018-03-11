/*
** EPITECH PROJECT, 2017
** File Name : split_header.c
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

char **split_header(char *str, char const *sep)
{
	char **arr = split(str, "\"");

	arr[0] = get_next_word(&str, sep);

	int i = 0;
	while (arr[i] != NULL) {
		printf("arr[%d] = %s\n", i, arr[i]);
		i++;
	}
	return(arr);
}
