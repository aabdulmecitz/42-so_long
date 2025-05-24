/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:24 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/24 21:52:54 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	*get_current_coin_frame(t_ctx *ctx)
{
	static clock_t	last_time = 0;
	static t_img	*current_frame = NULL;
	clock_t			current_time;
	double			elapsed_time;

	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 2000.0;
	if (current_frame == NULL)
		current_frame = ctx->coins;
	if (elapsed_time >= DELAY)
	{
		current_frame = current_frame->next;
		if (current_frame == NULL)
			current_frame = ctx->coins;
		last_time = current_time;
	}
	return (current_frame);
}

void	paint_coin_with_animation(t_ctx *ctx, int x, int y)
{
	t_img	*current_coin_frame;

	current_coin_frame = get_current_coin_frame(ctx);
	mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
current_coin_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}
