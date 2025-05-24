/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:52 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:09:54 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_object(t_ctx *ctx, int x, int y)
{
	if (ctx->map.map_matris[y][x] == COINS)
		ctx->map.coins--;
	else if (ctx->map.map_matris[y][x] == MAP_EXIT && ctx->map.coins == 0)
	{
		congrats_msg();
		win_destroy(ctx);
	}

}
void	ft_player_move(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		ctx->player_dir = BACK;
		ft_move_dir(ctx, 0, -1);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		ctx->player_dir = FRONT;
		ft_move_dir(ctx, 0, 1);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		ctx->player_dir = LEFT;
		ft_move_dir(ctx, -1, 0);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		ctx->player_dir = RIGHT;
		ft_move_dir(ctx, 1, 0);
	}
}

int	key_hook(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		win_destroy(ctx);
	ft_player_move(keycode, ctx);
	ft_print_map_map_matris(ctx);
	ft_printf(CYAN "The player's new location: (%d, %d)\nAll of coins: %d,\
		Movements: %d\n" RESET, ctx->map.player.x, ctx->map.player.y, \
		ctx->map.coins, ctx->movements);
	return (0);
}

void	ft_move_dir(t_ctx *ctx, int dx, int dy)
{
	int	x;
	int	y;

	x = ctx->map.player.x;
	y = ctx->map.player.y;
	if (ctx->map.map_matris[y + dy][x + dx] != WALL &&
		(ctx->map.map_matris[y + dy][x + dx] != MAP_EXIT || ctx->map.coins == 0))
	{
		ft_check_object(ctx, x + dx, y + dy);
		ctx->map.map_matris[y][x] = FLOOR;
		ctx->map.player.x += dx;
		ctx->map.player.y += dy;
		ctx->map.map_matris[y + dy][x + dx] = PLAYER;
		ctx->movements++;
	}
}

void	handler(t_ctx *ctx)
{
	mlx_hook(ctx->win_ptr, KeyPress, KeyPressMask, key_hook, ctx);
	mlx_hook(ctx->win_ptr, DestroyNotify, 0, win_destroy, ctx);
	mlx_hook(ctx->win_ptr, Expose, 0, render_a_frame, ctx);
}


