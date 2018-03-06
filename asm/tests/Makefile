##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rémi BISSON
##

NAME	=	units
CC	=	gcc
ROOT	=	$(realpath ../..)/
ASM	=	$(realpath ..)/
DSRC_UT	=	$(realpath .)/
INC	=	$(ASM)include/
DLIB	=	$(ROOT)lib/my/
DSRC	=	$(ASM)src/
DINIT	=	$(DSRC)init/

SRC	=	$(DSRC)asm.c \
		$(DSRC)op.c \
		$(DSRC)set_line.c \
		$(DINIT)init_buffer.c
		

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
