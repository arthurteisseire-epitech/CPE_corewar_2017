/*
** EPITECH PROJECT, 2017
** File Name : test_label.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "line.h"
#include "op.h"

Test(label, is_label)
{
	cr_expect(is_label("label:") != 0);
	cr_expect(is_label(":NOT_label") == 0);
	cr_expect(is_label("not_label") == 0);
	cr_expect(is_label("not:label") != 0);
}

Test(label, is_label_call)
{
	cr_expect(is_label_call("%:label_call") == 1);
	cr_expect(is_label_call("%:NOT_label_call") == 0);
	cr_expect(is_label_call("%not_label_call:") == 0);
	cr_expect(is_label_call(":not_label_call") == 0);
}
