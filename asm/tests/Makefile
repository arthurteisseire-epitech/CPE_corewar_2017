##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
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
DPARS	=	$(DSRC)parse/
LIB	=	my

SRC	=	$(DSRC)asm.c \
		$(DSRC)op.c \
		$(DSRC)set_line.c \
		$(DPARS)get_id_cmd.c \
		$(DPARS)parse_comments.c \
		$(DINIT)init_buffer.c


SRC_UT	=	$(SRC_UTD)get_id_cmd_test.c

OBJ	=	$(SRC:.c=.o) $(SRC_UT:.c=.o)
CFLAGS +=	-Wall -W -Wextra -I$(INC) --coverage
LDFLAGS	=	-lcriterion -lgcov
LIBS	=	-L$(DLIB) -l$(LIB)
BJ	=	$(SRC_UT:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_run: re
	./$(NAME)
