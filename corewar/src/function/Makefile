##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC	=	$(shell find . -type f -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
