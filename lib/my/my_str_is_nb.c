/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** my str is num?
*/

int my_str_is_num(char *str)
{
	int i = 0;

	while (str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] == '\0')) {
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
