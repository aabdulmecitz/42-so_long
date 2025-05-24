/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_a_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:59 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:09:00 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_texture(t_ctx *ctx, int x, int y);
void	put_player(t_ctx *ctx, int x, int y);

int	render_a_frame(t_ctx *ctx)
{
	int	x;
	int	y;

	handle_enemies(ctx);
	y = 0;
	while (y < ctx->map.rows + 2)
	{
		x = 0;
		while (x < ctx->map.columns)
		{
			if (y < ctx->map.rows)
				put_texture(ctx, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	print_space_line(t_ctx *ctx)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->map.rows + 2)
	{
		x = 0;
		while (x < ctx->map.columns)
		{
			if (!(y < ctx->map.rows))
			{
				mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
ctx->floor->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	put_texture(t_ctx *ctx, int x, int y)
{
	if (ctx->map.map_matris[y][x] == WALL)
		mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->wall->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == FLOOR)
		mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->floor->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == COINS)
		paint_coin_with_animation(ctx, x, y);
	else if (ctx->map.map_matris[y][x] == WANDER_ENEMY)
		mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->enemy_x->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == STAT_ENEMY)
		mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->enemy_k->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == PLAYER)
		put_player(ctx, x, y);
	else if (ctx->map.map_matris[y][x] == MAP_EXIT)
	{
		if (ctx->map.coins == 0)
			mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
					ctx->open_exit->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
		else
			mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
					ctx->exit_closed->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	}
}

void	put_player(t_ctx *ctx, int x, int y)
{
	if (ctx->player_dir == FRONT)
		mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->player_front->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->player_dir == BACK)
		mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->player_back->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->player_dir == LEFT)
		mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->player_left->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->player_dir == RIGHT)
		mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->player_right->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}
