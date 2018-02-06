/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** Rémi BISSON
*/
int my_strlen(char const *str)
{
 	int i = 0;

	if (str == (char *)0)
		return (0);
	while (str[i] != '\0')
	 	i++;
	return(i);
}
