/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:16:28 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 14:14:17 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <unistd.h>

# define IMG_HEIGHT 32
# define IMG_WIDTH 32

# define WIN_H 1080
# define WIN_W 1920

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_Q 113
# define KEY_ESC 65307

# define WALL_XPM "assets/sprites/dungeonwall.xpm"
# define FLOOR_XPM "assets/sprites/floor.xpm"
# define COINS_XPM "assets/sprites/coin/coin1.xpm"
# define PLAYER_FRONT_XPM "assets/sprites/player/front/player17.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/player/left/player9.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/player/right/player1.xpm"
# define PLAYER_BACK_XPM "assets/sprites/player/back/player25.xpm"
# define OPEN_EXIT_XPM "assets/sprites/opened_door.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/dungeon_door.xpm"

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

typedef struct s_location
{
	int			x;
	int			y;
}				t_location;

typedef enum e_dir
{
	FRONT,
	BACK,
	LEFT,
	RIGHT
}				t_dir;

typedef struct s_img
{
	void		*xpm_ptr;
	int			x;
	int			y;
}				t_img;

typedef struct s_map
{
	char		**map_matris;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_location	player;
}				t_map;

typedef struct s_ctx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	t_dir	player_dir;
	t_map		map;
	int		map_alloc;
	t_img		undefined_img;
	t_img		wall;
	t_img		floor;
	t_img		coins;
	t_img		open_exit;
	t_img		exit_closed;
	t_img		player_front;
	t_img		player_left;
	t_img		player_right;
	t_img		player_back;
}				t_ctx;

void			check_cmd_args(int argc, char const *argv[],
					t_ctx *ctx);
void			map_checker(t_ctx *ctx);
void			check_empty_lines(char *map, t_ctx *ctx);
void			error(char *msg, t_ctx *ctx);
void			so_long_init(t_ctx *ctx);
void			map_initializer(t_ctx *ctx, char *argv);
void			general_checker(t_ctx *ctx);
int				key_hook(int keycode, t_ctx *ctx);
int				check_collectables(t_map *map_c, t_map *map_e,
					t_ctx *ctx);
void			handler(t_ctx *ctx);
int				win_destroy(t_ctx *ctx);
void			congrats_msg(void);
int				render_a_frame(t_ctx *ctx);
int				update_frame(t_ctx *ctx);
void			free_double(void *ptr1, void *ptr2, void *ptr3, void *ptr4);
void			put_player(t_ctx *ctx, int x, int y);
void			free_all_mem(t_ctx *ctx);
void			free_map(t_ctx *ctx);
void			free_map_inside(t_map *map);
void			ft_print_map_map_matris(t_ctx *ctx);

#endif