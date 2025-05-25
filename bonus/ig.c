/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ig.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:04 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 20:38:33 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	conf_null(t_ctx *ctx)
{
	ctx->enemy = NULL;
	ctx->wall = NULL;
	ctx->floor = NULL;
	ctx->coins = NULL;
	ctx->player_front = NULL;
	ctx->player_left = NULL;
	ctx->player_right = NULL;
	ctx->player_back = NULL;
	ctx->open_exit = NULL;
	ctx->exit_closed = NULL;
	ctx->enemy_x = NULL;
	ctx->enemy_k = NULL;
}

void	load_all_sprites(t_ctx *ctx)
{
	void	*mlx;

	mlx = ctx->mlx_ptr;
	load_sprite(ctx->wall, mlx, WALL_XPM1, ctx);
	load_sprite(ctx->floor, mlx, FLOOR_XPM, ctx);
	load_sprite(ctx->coins, mlx, COINS_XPM1, ctx);
	load_sprite(ctx->player_front, mlx, PLAYER_FRONT_XPM, ctx);
	load_sprite(ctx->player_left, mlx, PLAYER_LEFT_XPM, ctx);
	load_sprite(ctx->player_right, mlx, PLAYER_RIGHT_XPM, ctx);
	load_sprite(ctx->player_back, mlx, PLAYER_BACK_XPM, ctx);
	load_sprite(ctx->open_exit, mlx, OPEN_EXIT_XPM, ctx);
	load_sprite(ctx->exit_closed, mlx, EXIT_CLOSED_XPM, ctx);
	load_sprite(ctx->enemy_x, mlx, WANDER_ENEMY_XPM, ctx);
	load_sprite(ctx->enemy_k, mlx, TOXIC_XPM1, ctx);
}
