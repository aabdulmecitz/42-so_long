NAME            = so_long
NAME_BONUS      = so_long_bonus

# Paths
SRCS_DIR        = ./src/
BONUS_SRCS_DIR  = ./bonus/
LIBFT_DIR       = ./lib/libft
MLX_DIR         = ./lib/minilibx-linux

LIBFT_A         = $(LIBFT_DIR)/libft.a
MLX_A           = $(MLX_DIR)/libmlx.a

# Compiler
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g
INCLUDES        = -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS            = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd

# Files
SRCS = $(addprefix $(SRCS_DIR),\
        button_acts.c check_cmd_args.c check_map.c \
        flood_fill.c frame_mount.c free.c free_all.c\
        game_initializer.c map_initializer.c msg.c so_long.c)

BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR),\
        animation_creator.c button_acts.c check_cmd_args.c get_player_frame.c\
        check_map.c get_frame.c paint_frame.c enemy_acts.c flood_fill.c \
        enemy_init.c frame_mount.c free_all.c free.c ig.c write_steps.c\
        game_initializer.c map_initializer.c msg.c so_long_bonus.c)

# Object files
OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(LIBFT_A) $(LIBS) -o $@
	@echo "$(NAME) built."

bonus: $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_SRCS) $(LIBFT_A) $(LIBS) -o $(NAME_BONUS)
	@echo "$(NAME_BONUS) built."

$(LIBFT_A):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

$(MLX_A):
	@echo "Compiling mlx..."
	@make -C $(MLX_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "Cleaned libraries."

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "Removed binaries."

re: fclean all

run: all
	./$(NAME) ./assets/maps/valid/map2.ber

.PHONY: all clean fclean re bonus
