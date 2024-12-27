/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:42 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:08:43 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_game(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);

void	ft_init_game(t_game *game)
{
	game->game_num = 0;
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->enemy_k_num = 0;
	game->enemy_x_num = 0;
	conf_null(game);
	game->map.columns = ft_strlen(game->map.full[0]) - 1;
	while (game->map.full[game->map.rows])
		game->map.rows++;
	game->player_direction = FRONT;
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_printf(GREEN "Game initialization successful!\n" RESET);
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error_msg("Couldn't find mlx pointer. Try it using a VNC.", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->map.columns + 1) * IMG_WIDTH,
			(game->map.rows + 2) * IMG_HEIGHT, "so_long");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't create the Window.", game);
	}
}

void	ft_load_sprite(t_image *sprite, void *mlx, char *path, t_game *game)
{
	if (!sprite)
		ft_error_msg("Sprite pointer is NULL.", game);
	sprite->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite->x, &sprite->y);
	ft_printf(CYAN "Loading sprite from path: %s\n" RESET, path);
	if (!sprite->xpm_ptr)
	{
		ft_printf(RED "Failed to load sprite: %s\n" RESET, path);
		ft_error_msg("Couldn't find a sprite. Does it exist?", game);
	}
}

void	ft_init_sprites(t_game *game)
{
	game->wall = malloc(sizeof(t_image));
	game->floor = malloc(sizeof(t_image));
	game->coins = malloc(sizeof(t_image));
	game->player_front = malloc(sizeof(t_image));
	game->player_left = malloc(sizeof(t_image));
	game->player_right = malloc(sizeof(t_image));
	game->player_back = malloc(sizeof(t_image));
	game->open_exit = malloc(sizeof(t_image));
	game->exit_closed = malloc(sizeof(t_image));
	game->enemy_x = malloc(sizeof(t_image));
	game->enemy_k = malloc(sizeof(t_image));
	if (!game->wall || !game->floor || !game->coins
		|| !game->player_front || !game->player_left
		|| !game->player_right || !game->player_back
		|| !game->open_exit || !game->exit_closed
		|| !game->enemy_x || !game->enemy_k)
		ft_error_msg("Memory allocation failed for one of the sprites.", game);
	load_all_sprites(game);
}
