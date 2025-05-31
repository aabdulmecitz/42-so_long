/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:51 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/31 18:46:38 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_destroy_imgs(t_ctx *ctx);

void	free_all_mem(t_ctx *ctx)
{
	if (!ctx)
		return ;
	ft_destroy_imgs(ctx);
	if (ctx->map_alloc && ctx->map.map_matris)
		free_map(ctx);
		free_double(ctx->wall, ctx->floor, ctx->coins, ctx->player_front);
	free_double(ctx->player_left, ctx->player_right, ctx->player_back, ctx->exit_closed);
	free_double(ctx->open_exit, ctx->enemy_x_l, ctx->enemy_x_r, ctx->enemy_k);
	if (ctx->mlx_ptr)
	{
		if (ctx->win_ptr)
		{
			mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
			ctx->win_ptr = NULL;
		}
		mlx_destroy_display(ctx->mlx_ptr);
		free(ctx->mlx_ptr);
		ctx->mlx_ptr = NULL;
	}
	free(ctx);
}

static void	ft_destroy_imgs(t_ctx *ctx)
{
	if (!ctx || !ctx->mlx_ptr)
		return ;
	if (ctx->wall && ctx->wall->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->wall->xpm_ptr);
	if (ctx->floor && ctx->floor->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->floor->xpm_ptr);
	if (ctx->coins && ctx->coins->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->coins->xpm_ptr);
	if (ctx->player_front && ctx->player_front->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->player_front->xpm_ptr);
	if (ctx->player_left && ctx->player_left->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->player_left->xpm_ptr);
	if (ctx->player_right && ctx->player_right->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->player_right->xpm_ptr);
	if (ctx->player_back && ctx->player_back->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->player_back->xpm_ptr);
	if (ctx->exit_closed && ctx->exit_closed->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->exit_closed->xpm_ptr);
	if (ctx->open_exit && ctx->open_exit->xpm_ptr)
		mlx_destroy_image(ctx->mlx_ptr, ctx->open_exit->xpm_ptr);
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
