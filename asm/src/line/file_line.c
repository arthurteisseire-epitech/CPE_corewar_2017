/*
** EPITECH PROJECT, 2017
** File Name : get_file_line.c
** File description:
** by Arthur Teisseire
*/

int file_line(int increment)
{
	static int real_index = 0;

	real_index += increment;
	return (real_index);
}
