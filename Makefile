# Program adı
NAME = so_long

# Kaynak ve nesne dosyaları
SRCS = src/main.c src/ft_init_game.c src/ft_error_msg.c src/ft_check_command_line_args.c src/ft_init_map.c
OBJS = $(SRCS:.c=.o)

# Kütüphaneler
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# MinilibX kütüphanesi
MLX_DIR = ./minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Komutlar ve bayraklar
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -I./src -I$(LIBFT_DIR) -I$(PRINTF_DIR)
RM = rm -f

# Varsayılan hedef
all: $(LIBFT) $(PRINTF) $(NAME)

# so_long programını derleme
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) $(PRINTF) -o $(NAME)

# Libft ve ft_printf kütüphanelerini derleme
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Nesne dosyalarını temizleme
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

# Bütün dosyaları temizleme
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

# Yeniden derleme
re: fclean all

# Programı yeniden derleyip çalıştırma hedefi
run: re
	./$(NAME)

# .PHONY hedefleri
.PHONY: all clean fclean re run
