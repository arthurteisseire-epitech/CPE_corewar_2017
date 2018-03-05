##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rémi BISSON
##

NAME	=	units
CC	=	gcc
DSRC	=	$(realpath ../src)/
INC	=	$(realpath ../include)/
DLIB	=	$(realpath ../lib/my)/
DSRC_UT	=	$(realpath .)/

SRC	=	$(DSRC)file.c

SRC_UT	=	$(SRC_UTD)tests.c

OBJ	=	$(SRC:.c=.o) $(SRC_UT:.c=.o)
CFLAGS +=	-Wall -W -Wextra -I$(INC) --coverage
LDFLAGS	=	-lcriterion -lgcov
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)

all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C $(DLIB)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBS)

clean:
	make clean -C $(DLIB)
	rm -f $(OBJ)

fclean:	clean
	make fclean -C $(DLIB)
	rm -f $(NAME)

re:	fclean all

test_run: all
	./$(NAME)
