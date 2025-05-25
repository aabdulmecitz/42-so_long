/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:30 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 15:49:28 by aozkaya          ###   ########.fr       */
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
	// Coin animasyonu
	init_animation(ctx, ctx->coins, 
		"assets/sprites/coin/coin2.xpm",
		"assets/sprites/coin/coin3.xpm", 
		"assets/sprites/coin/coin4.xpm", 
		NULL);

	// Duvar animasyonu
	init_animation(ctx, ctx->wall,
		WALL_XPM2,
		WALL_XPM3,
		WALL_XPM4,
		NULL);

	// Toxic river animasyonu 
	init_animation(ctx, ctx->enemy_k,
		TOXIC_XPM2,
		TOXIC_XPM3,
		TOXIC_XPM4,
		NULL);
}

// Paint fonksiyonlarını ekleyin
void    paint_wall_with_animation(t_ctx *ctx, int x, int y)
{
    static clock_t    last_time = 0;
    static t_img      *wall_frame = NULL;
    clock_t          current_time;
    double           elapsed_time;

    current_time = clock();
    if (wall_frame == NULL)
        wall_frame = ctx->wall;

    elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 1000.0;
    
    // Normal hızda animasyon
    if (elapsed_time >= DELAY)
    {
        wall_frame = wall_frame->next;
        if (wall_frame == NULL)
            wall_frame = ctx->wall;
        last_time = current_time;
    }
    
    mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, 
        wall_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void    paint_toxic_with_animation(t_ctx *ctx, int x, int y)
{
    t_img    *current_frame;
    static clock_t    last_time = 0;
    static t_img    *toxic_frame = NULL;
    clock_t        current_time;

    current_time = clock();
    if (toxic_frame == NULL)
        toxic_frame = ctx->enemy_k;
    if ((double)(current_time - last_time) / CLOCKS_PER_SEC * 1000.0 >= DELAY)
    {
        toxic_frame = toxic_frame->next;
        if (toxic_frame == NULL)
            toxic_frame = ctx->enemy_k;
        last_time = current_time;
    }
    mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, 
        toxic_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	img_creator(t_ctx *ctx, t_img *new_img,
		const char *current_path)
{
	if (!new_img)
		error("Memory allocation failed for img node.", ctx);
	load_sprite(new_img, ctx->mlx_ptr, (char *)current_path, ctx);
	new_img->next = NULL;
}
