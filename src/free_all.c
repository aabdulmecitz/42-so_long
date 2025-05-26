/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:10:09 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/26 04:42:26 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_destroy_imgs(t_ctx *ctx);

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

static void	ft_destroy_imgs(t_ctx *ctx)
{
	int i;

	if (!ctx || !ctx->mlx_ptr)
		return ;
	t_img	*imgs[] = {
		&ctx->wall, &ctx->floor, &ctx->coins,
		&ctx->player_front, &ctx->player_left,
		&ctx->player_right, &ctx->player_back,
		&ctx->exit_closed, &ctx->open_exit, NULL
	};
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
