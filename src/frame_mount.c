/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_a_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:10:21 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:12:11 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture(t_ctx *ctx, int x, int y);

int	render_a_frame(t_ctx *ctx)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->map.rows)
	{
		x = 0;
		while (x < ctx->map.columns)
		{
			put_texture(ctx, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	put_player(t_ctx *ctx, int x, int y)
{
	if (ctx->player_dir == FRONT)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->player_front.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->player_dir == BACK)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->player_back.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->player_dir == LEFT)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->player_left.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->player_dir == RIGHT)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->player_right.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	put_texture(t_ctx *ctx, int x, int y)
{
	if (ctx->map.map_matris[y][x] == WALL)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->wall.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == FLOOR)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->floor.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == COINS)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->coins.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == PLAYER)
		put_player(ctx, x, y);
	else if (ctx->map.map_matris[y][x] == MAP_EXIT)
	{
		if (ctx->map.coins == 0)
			mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
					ctx->open_exit.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
		else
			mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
					ctx->exit_closed.xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	}
}
