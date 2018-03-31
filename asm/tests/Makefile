##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

NAME	=	units
CC	=	gcc
ROOT	=	../
DSRC	=	$(ROOT)src/
INC	=	$(ROOT)include/
DLIB	=	$(ROOT)../lib/my/
DPARSE	=	$(DSRC)parse/
DBUFFER	=	$(DSRC)buffer/
DLINE	=	$(DSRC)line/
DTOKEN	=	$(DSRC)token/
DFREE	=	$(DSRC)free/
DHEADER	=	$(DSRC)header/
DSKIP	=	$(DSRC)skip/
DBINARY	=	$(DSRC)binary/
DLABEL	=	$(DSRC)label/

SRC	=	$(DSRC)asm.c \
		$(DSRC)op.c \
		$(DFREE)free.c \
		$(DLINE)set_line.c \
		$(DLINE)set_line_bytes.c \
		$(DTOKEN)set_token_bytes.c \
		$(DTOKEN)set_tokens.c \
		$(DTOKEN)init_tokens.c \
		$(DBUFFER)init_buffer.c \
		$(DBUFFER)set_buffer_bytes.c \
		$(DBUFFER)set_buffer.c \
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


SRC_UT	=	$(SRC_UTD)test_get_id_cmd.c \
		$(SRC_UTD)test_set_token_bytes.c \
		$(SRC_UTD)test_is_index.c \
		$(SRC_UTD)test_label.c

CFLAGS +=	-Wall -W -Wextra -I$(INC) --coverage
LDFLAGS	=	-lcriterion -lgcov
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)

all: $(NAME)

$(NAME):
	make -C ..
	gcc -o $(NAME) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_run: re
	./$(NAME)
	gcov *.gcno
