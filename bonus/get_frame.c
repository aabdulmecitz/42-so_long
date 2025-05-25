/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:24 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 20:31:43 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	paint_coin_with_animation(t_ctx *ctx, int x, int y)
{
	t_img	*current_coin_frame;

	current_coin_frame = get_coin_frame(ctx->coins);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
		current_coin_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void paint_wall_with_animation(t_ctx *ctx, int x, int y)
{
	t_img	*current_wall_frame;

	current_wall_frame = get_wall_frame(ctx->wall);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
		current_wall_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void paint_toxic_with_animation(t_ctx *ctx, int x, int y)
{
	t_img	*current_toxic_frame;

	current_toxic_frame = get_toxic_frame(ctx->enemy_k);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
		current_toxic_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

