NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c # Diğer kaynak dosyalarınızı da buraya ekleyin
OBJ = $(SRC:.c=.o)

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
