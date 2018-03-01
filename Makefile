##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

LIB	=	lib/my
ASM	=	asm
COREWAR	=	corewar

all:
	make -C $(LIB)
	make -C $(ASM)
	make -C $(COREWAR)

clean:
	make clean -C $(LIB)
	make clean -C $(ASM)
	make clean -C $(COREWAR)

fclean:
	make fclean -C $(LIB)
	make fclean -C $(ASM)
	make fclean -C $(COREWAR)

re: fclean all
