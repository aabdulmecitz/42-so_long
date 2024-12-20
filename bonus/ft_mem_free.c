/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:11:01 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/21 02:40:44 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_destroy_images(t_game *game);

void	ft_free_all_allocated_memory(t_game *game)
{
	if (!game)
		return ;
	ft_destroy_images(game);
	ft_free_map(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->enemy)
		free(game->enemy);
	free(game);
}

static void	ft_destroy_images(t_game *game)
{
	int		i;
	t_image	*images[10];

	i = 0;
	images[0] = game->wall;
	images[1] = game->floor;
	images[2] = game->coins;
	images[3] = game->player_front;
	images[4] = game->player_left;
	images[5] = game->player_right;
	images[6] = game->player_back;
	images[7] = game->exit_closed;
	images[8] = game->open_exit;
	images[9] = NULL;
	while (images[i])
	{
		if (images[i]->xpm_ptr)
			free_image_list(images[i], game->mlx_ptr);
		free(images[i]);
		i++;
	}
}

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map.full)
		return ;
	i = 0;
	while (i < game->map.rows)
		free(game->map.full[i++]);
	free(game->map.full);
}

void	ft_free_just_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->full[i]);
		i++;
	}
	free(map->full);
	free(map);
}

int	ft_destroy_window(t_game *game)
{
	if (!game)
	{
		ft_free_all_allocated_memory(game);
	}
	exit(0);
	return (0);
}
