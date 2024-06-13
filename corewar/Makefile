##
## EPITECH PROJECT, 2023
## make
## File description:
## make
##

SRC	=	src/main.c \
		src/gorbage_collector.c \
		src/init/init_struct.c \
		src/init/create_player.c \
		src/display/display_arena.c \
		src/display/display_error.c \
		src/display/display_result_arena.c \
		src/load/load.c \
		src/load/verif_help.c \
		src/load/load_arg/load_arg.c \
		src/load/load_arg/utils_arg.c \
		src/arena/home_arena.c \
		src/cmd/utils_cmd/change_carry.c \
		src/cmd/utils_cmd/is_register_or_nbr.c \
		src/arena/play_player.c \
		src/arena/prepa_champions/prepa_champions.c \
		src/arena/prepa_champions/get_program.c \
		src/arena/prepa_champions/utils_prepa.c \
		src/arena/convert.c \
		src/arena/check_live.c \
		src/arena/excute_cmd/home_excute_cmd.c \
		src/arena/excute_cmd/get_coding_bytes_arg.c \
		src/arena/excute_cmd/utils_excute.c \
		src/arena/check_cmd/check_cmd_is_good.c \
		src/arena/end_game.c \
		src/cmd/add.c \
		src/cmd/aff.c \
		src/cmd/and.c \
		src/cmd/fork.c \
		src/cmd/ld.c \
		src/cmd/ldi.c \
		src/cmd/live.c \
		src/cmd/lld.c \
		src/cmd/lldi.c \
		src/cmd/or.c \
		src/cmd/st.c \
		src/cmd/sti.c \
		src/cmd/sub.c \
		src/cmd/xor.c \
		src/cmd/zjmp.c \
		src/cmd/lfork.c \
		src/arena/excute_cmd/read_arena.c \


NAME	=	corewar

OBJ	= $(SRC:.c=.o)

CFLAGS	=	-g -W -Wall -Wextra -L./src/function/ -lmy -I./include/

all: $(NAME)

$(NAME):	$(OBJ)
	@echo -e "🔨 \033[0;32mCompile Corewar \033[0;30m🔨"
	cd src/function && make
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)
	@echo -e "✅ \033[0;31mCorewar is compiled ✅ \033[0m"

debug:
	cd src/function && make
	gcc -g $(OBJ) -o $(NAME) $(CFLAGS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) src/function/libmy.a
	cd src/function && make fclean
	rm -f libmy.a


re: fclean all
