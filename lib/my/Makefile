##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rémi BISSON
##
SRC	=	my_putchar.c	\
		my_putnbr.c	\
		my_putstr.c	\
		my_put_error.c	\
		my_strlen.c	\
		my_getnbr.c
OBJ	=	$(SRC:.c=.o)
INC	=	my.h
NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(INC) ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
