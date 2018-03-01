/*
** EPITECH PROJECT, 2017
** LIB
** File description:
** get nbr
*/

int my_getnbr(char *str)
{
	int i = 0;
	int nb = 0;
	int pos = 1;

	while (str[i] == '-') {
		i++;
		pos = pos * - 1;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		nb += str[i] - 48;
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			nb *= 10;
		i++;
	}
	return (nb * pos);
}
