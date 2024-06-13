##
## EPITECH PROJECT, 2023
## make
## File description:
## make
##

all:
	make -C lib/my
	make -C asm
	make -C corewar

debug:
	make debug -C asm
	make debug -C corewar

clean:
	make clean -C lib/my
	make clean -C asm
	make clean -C corewar
	rm -f libmy.a

fclean: clean
	make fclean -C lib/my
	make fclean -C asm
	make fclean -C corewar
	rm -f libmy.a

re:	fclean all
