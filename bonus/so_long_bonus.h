/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:16:28 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/14 18:59:30 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define ANIM_SPEED			1000

# define WIN_H				1080
# define WIN_W				1920

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'
# define STAT_ENEMY			'K'
# define WANDER_ENEMY		'X'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

# define WALL_XPM			"assets/sprites/dungeonwall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define COINS_XPM			"assets/sprites/coin/coin1.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/front/player17.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/left/player9.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/right/player1.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/back/player25.xpm"
# define OPEN_EXIT_XPM		"assets/sprites/opened_door.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/dungeon_door.xpm"
# define STAT_ENEMY_XPM		"assets/sprites/toxic-river.xpm"
# define WANDER_ENEMY_XPM	"assets/sprites/enemy/left/enemy1.xpm"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

typedef enum e_bool
{
	false,
	true
}	t_bool;


typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef enum e_direction
{
    FRONT,
    BACK,
    LEFT,
    RIGHT,
	HORIZONTAL,
	VERTICAL,
	IDLE
} t_direction;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef enum e_enemy_type
{
    ENEMY_FIXED,
    ENEMY_WANDERING
} t_enemy_type;

typedef struct s_enemy
{
	int x;
	int y;
	t_image sprite;
    t_enemy_type type;
    t_direction dir;
	struct s_enemy *next;
} t_enemy;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	t_direction	player_direction;
	t_enemy		*enemy_k;
	int			enemy_k_num;
    t_enemy		*enemy_x;
	int			enemy_x_num;
	int			game_num;
	t_map		map;
	t_bool		map_alloc;
	t_image		undefined_image;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;


void    ft_check_command_line_args(int argc, char const *argv[], t_game *game);
void    ft_check_map(t_game *game);
void    ft_check_for_empty_line(char *map, t_game *game);
void    ft_error_msg(char *msg, t_game *game);
void	ft_init_game(t_game *game);
void	ft_init_map(t_game *game, char *argv);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_just_map(t_map *map);
void    check_as_a_hero(t_game *game);
int		key_hook(int keycode, t_game *game);
int 	ft_check_all_collectables(t_map *map, t_game *game);
void    ft_handle_buttons(t_game *game);
int 	ft_destroy_window(t_game *game);
void    ft_congrats_message();
int		ft_render_frame(t_game *game);
int 	ft_update_frame(t_game *game);
void    ft_paint_texture(t_game *game, int x, int y);
void 	ft_check_collision_fixed_enemy(t_game *game);
void 	ft_check_collision_wandering_enemy(t_game *game);
void 	ft_move_enemy_x(t_game *game);
void    ft_failed_msg();
void    ft_init_enemy(t_game *game);
void 	handle_enemy(t_game *game, int x, int y);
void 	ft_allocate_enemy_memory(t_game *game);
void 	ft_load_sprite(t_image *sprite, void *mlx, char *path, t_game *game);
void    ft_enemies(t_game *game);
void    ft_enemy_movement(t_game *game, t_enemy *enemy);
int		is_valid_position(t_game *game, int x, int y);
void	ft_update_enemies(t_game *game);



void ft_print_map_full(t_game *game);



#endif