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
DTESTS	=	$(realpath tests)/
DLIB	=	$(ROOT)lib/my/
DINIT	=	$(DSRC)init/
DPARSE	=	$(DSRC)parse/

SRC	=	$(DSRC)main.c \
		$(DSRC)asm.c \
		$(DSRC)set_line.c \
		$(DSRC)op.c \
		$(DINIT)init_buffer.c \
		$(DPARSE)get_id_cmd.c \
		$(DPARSE)parse_comments.c

OBJ	=	$(SRC:.c=.o)
CFLAGS +=	-Wall -W -Wextra -I$(INC) -g
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
NAME	=	asm

all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C $(DLIB)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
	make clean -C $(DLIB)
	rm -f $(OBJ)

fclean:	clean
	make fclean -C $(DLIB)
	rm -f $(NAME)

re:	fclean all

test_run:
	make test_run -C $(DTESTS)
