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
LIB	=	my
DSRC	=	$(ASM)src/
DINIT	=	$(DSRC)init/
DPARSE	=	$(DSRC)parse/
DBUFFER	=	$(DSRC)buffer/
DLINE	=	$(DSRC)line/
DTOKEN	=	$(DSRC)token/
DFREE	=	$(DSRC)free/

SRC	=	$(DSRC)asm.c \
		$(DSRC)op.c \
		$(DSRC)put_err_asm.c \
		$(DSRC)set_header.c \
		$(DFREE)free.c \
		$(DLINE)set_line.c \
		$(DLINE)set_line_bytes.c \
		$(DLINE)file_line.c \
		$(DTOKEN)set_token_bytes.c \
		$(DTOKEN)set_tokens.c \
		$(DTOKEN)init_tokens.c \
		$(DTOKEN)get_cbyte.c \
		$(DBUFFER)init_buffer.c \
		$(DBUFFER)set_buffer_bytes.c \
		$(DPARSE)get_id_cmd.c \
		$(DPARSE)label.c \
		$(DPARSE)skip_comments.c \
		$(DPARSE)is_line_valid.c

SRC_UT	=	$(SRC_UTD)test_get_id_cmd.c \
		$(SRC_UTD)test_set_token_bytes.c \
		$(SRC_UTD)test_is_index.c \
		$(SRC_UTD)test_label.c \
		$(SRC_UTD)test_check_label_buffer.c \
		$(SRC_UTD)test_get_token_value.c

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
