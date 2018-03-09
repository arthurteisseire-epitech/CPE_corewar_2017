/*
** EPITECH PROJECT, 2017
** File Name : test_get_label_buffer.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "parse.h"
#include "op.h"
#include "buffer.h"
#include "errors.h"
#include "line.h"
#include "token.h"

Test(check_label_buffer, check_buffer)
{
	buffer_t buffer;

	my_asm(&buffer, "check_label_buffer.s");
}
