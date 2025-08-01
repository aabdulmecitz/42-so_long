/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:10:09 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/31 19:01:55 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_mem(t_ctx *ctx)
{
	if (!ctx)
		return ;
	ft_destroy_imgs(ctx);
	if (ctx->map_alloc)
		free_map(ctx);
	if (ctx->mlx_ptr)
	{
		if (ctx->win_ptr)
			mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
		mlx_destroy_display(ctx->mlx_ptr);
		free(ctx->mlx_ptr);
		ctx->mlx_ptr = NULL;
	}
	free(ctx);
}

void	ft_destroy_imgs(t_ctx *ctx)
{
	int		i;
	t_img	*imgs[10];

	imgs[0] = &ctx->wall;
	imgs[1] = &ctx->floor;
	imgs[2] = &ctx->coins;
	imgs[3] = &ctx->player_front;
	imgs[4] = &ctx->player_left;
	imgs[5] = &ctx->player_right;
	imgs[6] = &ctx->player_back;
	imgs[7] = &ctx->exit_closed;
	imgs[8] = &ctx->open_exit;
	imgs[9] = NULL;
	if (!ctx || !ctx->mlx_ptr)
		return ;
	i = 0;
	while (imgs[i])
	{
		if (imgs[i]->xpm_ptr)
		{
			mlx_destroy_image(ctx->mlx_ptr, imgs[i]->xpm_ptr);
			imgs[i]->xpm_ptr = NULL;
		}
		i++;
	}
}

void	free_map(t_ctx *ctx)
{
	int	i;

	if (!ctx->map.map_matris)
		return ;
	i = 0;
	while (i < ctx->map.rows)
		free(ctx->map.map_matris[i++]);
	free(ctx->map.map_matris);
}

void	free_map_inside(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->map_matris[i]);
		i++;
	}
	free(map->map_matris);
	free(map);
}

int	win_destroy(t_ctx *ctx)
{
	if (!ctx)
	{
		free_all_mem(ctx);
	}
	exit(0);
	return (0);
}
