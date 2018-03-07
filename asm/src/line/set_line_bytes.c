/*
** EPITECH PROJECT, 2017
** File Name : get_line_bytes.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "asm.h"

static const char no_cbyte_inst[NB_NOCBYTE][6] = {
	"live",
	"zjmp",
	"fork",
	"lfork"
};
