/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** my is printable ?
*/

int my_is_printable(char c)
{
	if (c >= '!' && c <= '~')
		return (1);
	else
		return (0);
}