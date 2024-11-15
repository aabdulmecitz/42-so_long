NAME = so_long
SRCS = src/main.c src/ft_init_game.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
RM = rm -f

# Projeyi derleyen hedef
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)

# Varsayılan hedef
all: $(NAME)

# Object dosyalarını ve geçici dosyaları temizle
clean:
	$(RM) $(OBJS)

# Bütün dosyaları (çalıştırılabilir dosya dahil) temizle
fclean: clean
	$(RM) $(NAME)

# Yeniden derleme
re: fclean all

# Programı yeniden derleyip çalıştırma hedefi
run: re
	./so_long

.PHONY: all clean fclean re run
