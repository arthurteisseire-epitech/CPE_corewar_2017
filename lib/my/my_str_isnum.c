/*
** EPITECH PROJECT, 2017
** File Name: my_str_isnum
** File description:
** Ozz
*/

int my_str_isnum(char const *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
