/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:30 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/24 21:52:54 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_creator(t_ctx *ctx, t_img *new_img,
			const char *current_path);

void	init_animation(t_ctx *ctx, t_img *img, ...)
{
	va_list		args;
	t_img		*new_img;
	const char	*current_path;
	t_img		*temp;

	va_start(args, img);
	current_path = va_arg(args, const char *);
	temp = img;
	while (current_path != NULL)
	{
		new_img = malloc(sizeof(t_img));
		img_creator(ctx, new_img, current_path);
		temp->next = new_img;
		temp = temp->next;
		current_path = va_arg(args, const char *);
	}
	va_end(args);
}

void	init_all_of_animations(t_ctx *ctx)
{
	init_animation(ctx, ctx->coins, "assets/sprites/coin/coin2.xpm", \
"assets/sprites/coin/coin3.xpm", "assets/sprites/coin/coin4.xpm", NULL);
}

void	run_animation(t_ctx *ctx, t_img *img_list)
{
	static time_t	last_time;
	static t_img	*current_img;
	time_t			current_time;

	last_time = 0;
	current_img = NULL;
	current_time = time(NULL);
	if (difftime(current_time, last_time) * 1000 >= DELAY)
	{
		if (current_img == NULL)
			current_img = img_list;
		if (current_img && current_img->xpm_ptr)
		{
			mlx_put_img_to_window(ctx->mlx_ptr, ctx->win_ptr, \
					current_img->xpm_ptr, current_img->x, current_img->y);
		}
		current_img = current_img->next;
		if (current_img == NULL)
			current_img = img_list;
		last_time = current_time;
	}
}

void	img_creator(t_ctx *ctx, t_img *new_img,
		const char *current_path)
{
	if (!new_img)
		error("Memory allocation failed for img node.", ctx);
	load_sprite(new_img, ctx->mlx_ptr, (char *)current_path, ctx);
	new_img->next = NULL;
}
