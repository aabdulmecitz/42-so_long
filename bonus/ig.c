/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ig.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:04 by aozkaya           #+#    #+#             */
/*   Updated: 2025/06/10 18:04:16 by aozkaya          ###   ########.fr       */
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
	ctx->enemy_x_l = NULL;
	ctx->enemy_x_r = NULL;
	ctx->enemy_k = NULL;
}
