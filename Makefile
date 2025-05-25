NAME			= so_long
NAME_BONUS		= so_long_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= ./lib/libft/libft.a
MLX 			= ./lib/minilibx-linux/libmlx.a

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -lXext -lX11

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all

REMOVE 			= rm -f

SRCS_DIR		= ./src/
BONUS_SRCS_DIR	= ./bonus/

SRCS 			= $(addprefix $(SRCS_DIR),\
				button_acts.c check_cmd_args.c check_map.c \
				flood_fill.c frame_mount.c free.c free_all.c\
				game_initializer.c map_initializer.c msg.c so_long.c)

BONUS_SRC 		= $(addprefix $(BONUS_SRCS_DIR),\
				animation_creator.c button_acts.c check_cmd_args.c \
				check_map.c coin_animation.c enemy_acts.c flood_fill.c \
				enemy_init.c frame_mount.c free_all.c free.c ig.c write_steps.c\
				game_initializer.c map_initializer.c msg.c so_long_bonus.c)


all:			${LIBFT} ${MLX} ${NAME} 
bonus:			${LIBFT} ${MLX} ${NAME_BONUS} 

${NAME}: 		
				${CC} ${SRCS} ${LIBFT} -L./lib/minilibx-linux ${MLX} ${MINILIBX_FLAGS} -g -fsanitize=address -o ${NAME}
				make compile_libs
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

${NAME_BONUS}: 		
				${CC} ${BONUS_SRC} ${LIBFT} -L./lib/minilibx-linux ${MLX} ${MINILIBX_FLAGS} -g -fsanitize=address -o ${NAME_BONUS}
				@echo "$(NAME_BONUS): $(GREEN)$(NAME_BONUS) was compiled.$(RESET)"
				@echo

${MLX}:
				@echo "Compiling MLX..."
				make -C lib/minilibx-linux
				make clean lib/minilibx-linux
				@echo "MLX compiled successfully."

${LIBFT}:
				@echo "Compiling libft..."
				make -C lib/libft
				make clean lib/libft
				@echo "libft compiled successfully."

clean:
				make clean -C lib/libft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo
push:
	git add .
	git commit -m "commit"
	git push

re:				fclean all

re_bonus:	fclean bonus

compile_libs:
	@make -sC lib/libft
	@make -sC lib/minilibx-linux
	@make clean -sC lib/libft

update:
	git submodule update --init --recursive --remote

run:			re
				./${NAME} assets/maps/valid/map2.ber 

run_bonus:		re_bonus
				./${NAME_BONUS} assets/maps/valid/bonus/map5.ber 

valgrind: re
	$(VALGRIND) ./${NAME} assets/maps/valid/map2.ber 

valgrind_bonus:
	$(VALGRIND)  --leak-check=full ./so_long_bonus assets/maps/valid/bonus/map5.ber

norminette:
	norminette ./src && norminette ./bonus

.PHONY:			all clean fclean re rebonus valgrind run run_bonus makefile
