##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rémi BISSON
##

NAME	=	units
CC	=	gcc
SRC_DIR	=	$(realpath ../src)/
INC	=	$(realpath ../include)/
LIB_DIR	=	$(realpath ../lib/my)/
SRC_UTD	=	$(realpath .)/
SRC	=	$(SRC_DIR)file.c
SRC_UT	=	$(SRC_UTD)tests.c
OBJ	=	$(SRC:.c=.o) \
		$(SRC_UT:.c=.o)
CFLAGS +=	-Wall -W -Wextra -I$(INC) --coverage
LDFLAGS	=	-lcriterion -lgcov
LIB	=	my
LIBS	=	-L$(LIB_DIR) -l$(LIB)

all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean:	clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re:	fclean all clean

test_run: all
	./$(NAME)
