/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** LIB
*/

int my_char_is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}