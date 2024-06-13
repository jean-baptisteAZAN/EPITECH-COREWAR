##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

SRC     =       src/main.c \
				src/error/error_header.c \
				src/error/devide_st.c \
				src/gorbage_collector.c \
				src/error/display_error.c \
				src/error/error_format_name.c \
				src/parsing/home_parsing.c \
				src/error/gestion_arg.c \
				src/label/get_size.c \
				src/label/get_tab_label.c \
				src/label/utils_tab_label.c \
				src/label/my_memset.c \
				src/write_file/write_header.c \
				src/write_file/write_args.c \
				src/write_file/write/write_dir.c \
				src/utils/utils.c \
				op.c \
				bigendian.c \
				src/error/handle_command_errors.c \

NAME    =       asm

OBJ     = $(SRC:.c=.o)

CFLAGS  =       -L./../lib/my/ -lmy -I./../include/

all: $(NAME)

$(NAME):        $(OBJ)
		cd ../lib/my && make
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

debug:  fclean $(OBJ)
		cd ../lib/my && make
		gcc -g $(SRC) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
