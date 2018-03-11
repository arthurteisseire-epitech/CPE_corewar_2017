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
DPARSE	=	$(DSRC)parse/
DBUFFER	=	$(DSRC)buffer/
DLINE	=	$(DSRC)line/
DTOKEN	=	$(DSRC)token/
DFREE	=	$(DSRC)free/
DHEADER	=	$(DSRC)header/
DSKIP	=	$(DSRC)skip/
DBINARY	=	$(DSRC)binary/
DLABEL	=	$(DSRC)label/

SRC	=	$(DSRC)main.c \
		$(DSRC)asm.c \
		$(DSRC)op.c \
		$(DFREE)free.c \
		$(DLINE)set_line.c \
		$(DLINE)set_line_bytes.c \
		$(DTOKEN)set_token_bytes.c \
		$(DTOKEN)set_tokens.c \
		$(DTOKEN)init_tokens.c \
		$(DBUFFER)init_buffer.c \
		$(DBUFFER)set_buffer_bytes.c \
		$(DLABEL)is_label.c \
		$(DLABEL)replace_label.c \
		$(DPARSE)get_id_cmd.c \
		$(DPARSE)is_line_valid.c \
		$(DSKIP)check_label.c \
		$(DSKIP)skip_and_set_labels.c \
		$(DSKIP)skip_comments.c \
		$(DSKIP)skip_comments_and_labels.c \
		$(DBINARY)set_line_binary.c \
		$(DBINARY)write_binary.c \
		$(DBINARY)get_cbyte.c \
		$(DHEADER)check_header1.c \
		$(DHEADER)check_header2.c \
		$(DHEADER)put_err_asm.c \
		$(DHEADER)set_header.c \
		$(DHEADER)split_header.c

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
