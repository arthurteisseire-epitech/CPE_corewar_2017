#include <stdlib.h>
#include "my.h"
#include <stdio.h>

static int jump_space(char *str, int i, char c)
{
	while (str[i] != '\0' && str[i] == c)
		i++;
	return (i);
}

static int res_len(char *str, char c)
{
	int i = jump_space(str, 0, c);
	int j = 0;

	while (str[i] != '\0') {
		i++;
		j++;
		if (str[i] == c) {
			j++;
			i = jump_space(str, i, c);
		}
	}
	if (j != 0 && str[i - 1] == c)
		j--;
	return (j);
}

static char *cpy_res(char *res, char *str, int size, char c)
{
	int i = jump_space(str, 0, c);
	int j = 0;

	while (str[i] != '\0' && j != size) {
		res[j] = str[i];
		i++;
		j++;
		if (str[i] == c) {
			res[j] = str[i];
			j++;
			i = jump_space(str, i, c);
		}
	}
	res[size] = '\0';
	return (res);
}

char *my_clean_str(char *str, char c)
{
	int size = res_len(str, c);
	char *res = malloc(sizeof(char) * (size + 1));

	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	res = cpy_res(res, str, size, c);
	free(str);
	return (res);
}
