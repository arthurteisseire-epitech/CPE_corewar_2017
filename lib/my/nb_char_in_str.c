/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** check nb of char in a str
*/

int nb_char_in_str(char c, char *str)
{
	int i = 0;
	int occ = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			occ++;
		i++;
	}
	return (occ);
}