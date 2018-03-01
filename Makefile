##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Ozz
##
NAME	=	corewar
CC	=	gcc
SRC_DIR	=	$(realpath src)/
INC	=	$(realpath include)/
LIB_DIR	=	$(realpath lib/my)/
SRC	=	$(SRC_DIR)main.c
OBJ	=	$(SRC:.c=.o)
CFLAGS +=	-Wall -W -Wextra -I$(INC)
LIB	=	my
LIBS	=	-L$(LIB_DIR) -l$(LIB)

all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean:	clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re:	fclean all clean
