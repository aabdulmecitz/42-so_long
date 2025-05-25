/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:11 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 20:32:54 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>
# include <time.h>
# include <unistd.h>

# define IMG_HEIGHT 32
# define IMG_WIDTH 32

# define DELAY 80  // Animasyon hızı artırıldı (150'den 80'e düşürüldü)

# define WIN_H 1080
# define WIN_W 1920

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'
# define STAT_ENEMY 'K'
# define WANDER_ENEMY 'X'

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

# define WALL_XPM1 "assets/sprites/wall/dungeonwall.xpm"
# define WALL_XPM2 "assets/sprites/wall/dungeonwall2.xpm"
# define WALL_XPM3 "assets/sprites/wall/dungeonwall3.xpm"
# define WALL_XPM4 "assets/sprites/wall/dungeonwall4.xpm"
# define WALL_XPM5 "assets/sprites/wall/dungeonwall5.xpm"  // Yeni eklenen tanım
# define FLOOR_XPM "assets/sprites/floor.xpm"
# define COINS_XPM "assets/sprites/coin/coin1.xpm"
# define PLAYER_FRONT_XPM "assets/sprites/player/front/player17.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/player/left/player9.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/player/right/player1.xpm"
# define PLAYER_BACK_XPM "assets/sprites/player/back/player25.xpm"
# define OPEN_EXIT_XPM "assets/sprites/door/opened_door/opened_door.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/door/dungeon_door.xpm"
# define STAT_ENEMY_XPM "assets/sprites/toxic_river/toxic-river.xpm"
# define WANDER_ENEMY_XPM "assets/sprites/enemy/left/enemy1.xpm"
# define TOXIC_XPM1 "assets/sprites/toxic_river/toxic-river.xpm"
# define TOXIC_XPM2 "assets/sprites/toxic_river/toxic-river2.xpm"
# define TOXIC_XPM3 "assets/sprites/toxic_river/toxic-river3.xpm"
# define TOXIC_XPM4 "assets/sprites/toxic_river/toxic-river4.xpm"

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

typedef struct s_location
{
	int				x;
	int				y;
}					t_location;

typedef enum e_dir
{
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	HORIZONTAL,
	VERTICAL,
	IDLE
}					t_dir;

typedef struct s_img
{
	void			*xpm_ptr;
	int				x;
	int				y;
	struct s_img	*next;
}					t_img;

typedef struct s_map
{
	char			**map_matris;
	int				rows;
	int				columns;
	int				coins;
	int				exit;
	int				players;
	t_location		player;
}					t_map;

typedef enum e_enemy_type
{
	ENEMY_FIXED,
	ENEMY_WANDERING
}					t_enemy_type;

typedef struct s_enemy
{
	int				x;
	int				y;
	t_dir			dir;
	time_t			last_move_time;
	struct s_enemy	*next;
}					t_enemy;

typedef struct s_ctx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				movements;
	t_dir			player_dir;
	int				enemy_k_num;
	int				enemy_x_num;
	int				ctx_num;
	int				map_alloc;
	t_map			map;
	t_img			*undefined_img;
	t_img			*wall;
	t_img			*floor;
	t_img			*coins;
	t_img			*open_exit;
	t_img			*exit_closed;
	t_img			*player_front;
	t_img			*player_left;
	t_img			*player_right;
	t_img			*player_back;
	t_enemy			*enemy;
	t_img			*enemy_k;
	t_img			*enemy_x;
}					t_ctx;

void				check_cmd_args(int argc, char const *argv[],
						t_ctx *ctx);
void				map_checker(t_ctx *ctx);
void				check_empty_lines(char *map, t_ctx *ctx);
void				error(char *msg, t_ctx *ctx);
void				so_long_init(t_ctx *ctx);
void				map_initializer(t_ctx *ctx, char *argv);
void				free_all_mem(t_ctx *ctx);
void				free_map(t_ctx *ctx);
void				free_map_inside(t_map *map);
void				general_checker(t_ctx *ctx);
int					key_hook(int keycode, t_ctx *ctx);
int					check_collectables(t_map *map_c, t_map *map_e,
						t_ctx *ctx);
void				handler(t_ctx *ctx);
int					win_destroy(t_ctx *ctx);
void				congrats_msg(void);
int					render_a_frame(t_ctx *ctx);
int					update_frame(t_ctx *ctx);
void				put_texture(t_ctx *ctx, int x, int y);
void				check_collision_fixed_enemy(t_ctx *ctx);
void				check_collision_wandering_enemy(t_ctx *ctx);
void				mv_enemy_x(t_ctx *ctx);
void				failed_msg(void);
void				init_enemies(t_ctx *ctx);
void				handle_enemies(t_ctx *ctx);
void				allocate_enemy_memory(t_ctx *ctx);
void				load_sprite(t_img *sprite, void *mlx, char *path,
						t_ctx *ctx);
void				ft_enemies(t_ctx *ctx);
void				enemy_movement(t_ctx *ctx, t_enemy *enemy);
int					is_valid_location(t_ctx *ctx, int x, int y);
void				update_enemies(t_ctx *ctx);
void	write_steps(t_ctx *ctx, int x, int y);
void				init_coin_animation(t_ctx *ctx);
void				ft_update_coin_animation(t_ctx *ctx);
void				free_coin_animation(t_ctx *ctx);
void				init_animation(t_ctx *ctx, t_img *img, ...);
void				init_all_of_animations(t_ctx *ctx);
void				run_animation(t_ctx *ctx, t_img *img_list);
void				paint_coin_with_animation(t_ctx *ctx, int x, int y);
void				free_double(void *ptr1, void *ptr2, void *ptr3, void *ptr4);
void				conf_null(t_ctx *ctx);
void				load_all_sprites(t_ctx *ctx);
void				free_img_list(t_img *head, void *mlx_ptr);
int					print_space_line(t_ctx *ctx);
void paint_wall_with_animation(t_ctx *ctx, int x, int y);

t_img	*get_coin_frame(t_img *frame);
t_img	*get_wall_frame(t_img *frame);
t_img	*get_toxic_frame(t_img *frame);

#endif