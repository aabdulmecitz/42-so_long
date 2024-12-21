/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 05:38:38 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/21 17:05:50 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_paint_texture(t_game *game, int x, int y);
void	put_player(t_game *game, int x, int y);

int	ft_render_frame(t_game *game)
{
	int	x;
	int	y;

	ft_handle_enemies(game);
	y = 0;
	while (y < game->map.rows + 2)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (y < game->map.rows)
				ft_paint_texture(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	print_space_line(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows + 2)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!(y < game->map.rows))
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
game->floor->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_paint_texture(t_game *game, int x, int y)
{
	if (game->map.full[y][x] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->wall->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->map.full[y][x] == FLOOR)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->floor->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->map.full[y][x] == COINS)
		ft_paint_coin_with_animation(game, x, y);
	else if (game->map.full[y][x] == WANDER_ENEMY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->enemy_x->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->map.full[y][x] == STAT_ENEMY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->enemy_k->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->map.full[y][x] == PLAYER)
		put_player(game, x, y);
	else if (game->map.full[y][x] == MAP_EXIT)
	{
		if (game->map.coins == 0)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->open_exit->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->exit_closed->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	}
}

void	put_player(t_game *game, int x, int y)
{
	if (game->player_direction == FRONT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->player_front->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->player_direction == BACK)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->player_back->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->player_direction == LEFT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->player_left->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->player_direction == RIGHT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->player_right->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}
