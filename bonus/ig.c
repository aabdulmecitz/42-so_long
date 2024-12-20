/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ig.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:18:48 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/21 01:26:08 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	conf_null(t_game *game)
{
	game->enemy = NULL;
	game->wall = NULL;
	game->floor = NULL;
	game->coins = NULL;
	game->player_front = NULL;
	game->player_left = NULL;
	game->player_right = NULL;
	game->player_back = NULL;
	game->open_exit = NULL;
	game->exit_closed = NULL;
	game->enemy_x = NULL;
	game->enemy_k = NULL;
}

void	load_all_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	ft_load_sprite(game->wall, mlx, WALL_XPM, game);
	ft_load_sprite(game->floor, mlx, FLOOR_XPM, game);
	ft_load_sprite(game->coins, mlx, COINS_XPM, game);
	ft_load_sprite(game->player_front, mlx, PLAYER_FRONT_XPM, game);
	ft_load_sprite(game->player_left, mlx, PLAYER_LEFT_XPM, game);
	ft_load_sprite(game->player_right, mlx, PLAYER_RIGHT_XPM, game);
	ft_load_sprite(game->player_back, mlx, PLAYER_BACK_XPM, game);
	ft_load_sprite(game->open_exit, mlx, OPEN_EXIT_XPM, game);
	ft_load_sprite(game->exit_closed, mlx, EXIT_CLOSED_XPM, game);
	ft_load_sprite(game->enemy_x, mlx, WANDER_ENEMY_XPM, game);
	ft_load_sprite(game->enemy_k, mlx, STAT_ENEMY_XPM, game);
}
