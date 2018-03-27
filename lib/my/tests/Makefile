##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

DSRC_UT	=	./
DLIB	=	../
INC	=	$(DLIB)
SRC_UT	=	$(DSRC_UT)redirect.c \
		$(DSRC_UT)tests_output.c \
		$(DSRC_UT)tests_cpy.c \
		$(DSRC_UT)tests_strcat.c \
		$(DSRC_UT)tests_atoi.c \
		$(DSRC_UT)tests_base.c \
		$(DSRC_UT)tests_split.c \
		$(DSRC_UT)tests_get_next_line.c \
		$(DSRC_UT)tests_cmp.c
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
CFLAGS	=	-Wall -W -Wextra --coverage -I$(INC)
LDFLAGS	=	-lcriterion -lgcov
OBJ	=	$(SRC_UT:.c=.o)
NAME	=	units

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
