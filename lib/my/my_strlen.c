/*
** EPITECH PROJECT, 2017
** lib
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}