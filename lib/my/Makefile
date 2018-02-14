##
## EPITECH PROJECT, 2017
## LIB
## File description:
## makefile for lib
##

LIB		=	my_putchar.c  			\
			my_putstr.c 			\
			my_puterr.c 			\
			my_strlen.c 			\
			my_getnbr.c 			\
			free_array.c 			\
			my_show_array.c 		\
			my_putnbr.c 			\
			itos.c 					\
			stoi.c 					\
			my_strdup.c 			\
			my_strcat.c 			\
			my_char_is_num.c 		\
			my_char_is_alpha.c 		\
			my_char_is_alpha_num.c 	\
			my_strcmp.c 			\
			my_strncmp.c 			\
			my_strtab.c 			\
			is_in_str.c 			\
			my_strnlcpy.c 			\
			my_arrcpy.c 			\
			my_is_printable.c 		\
			my_cleanstr.c 			\
			my_str_is_nb.c 			\
			my_str_is_alpha_num.c 	\
			my_arrlen.c 			\
			read_fullfill.c 		\


OBJ		=	$(LIB:.c=.o)

CFLAGS	=	-I../../include

NAME	=	libmy.a


$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
