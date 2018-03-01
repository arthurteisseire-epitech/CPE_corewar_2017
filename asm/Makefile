##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rémi BISSON
##

CC	=	gcc
ROOT	=	$(realpath ..)/
DSRC	=	$(realpath src)/
INC	=	$(realpath include)/
DLIB	=	$(ROOT)lib/my/
SRC	=	$(DSRC)main.c
OBJ	=	$(SRC:.c=.o)
CFLAGS +=	-Wall -W -Wextra -I$(INC)
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
NAME	=	asm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all clean
