/*
** EPITECH PROJECT, 2017
** File Name : get_file_line.c
** File description:
** by Arthur Teisseire
*/

int increment_file_line(int increment)
{
	static int real_index = 1;

	if (increment == -1)
		real_index = 0;
	else
		real_index += increment;
	return (real_index);
}
