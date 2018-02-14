/*
** EPITECH PROJECT, 2017
** LIB
** File description:
** str to int
*/

int stoi(char *str)
{
	int i = 0;
	int nb = 0;
	int isneg = 1;

	while (str[i] == '-') {
		i++;
		isneg = isneg * -1;
	}
	while (str[i] != '\0') {
		nb = nb + str[i] - 48;
		if (str[i + 1] != '\0')
			nb *= 10;
		i++;
	}
	return (nb * isneg);
}
