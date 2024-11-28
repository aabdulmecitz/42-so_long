/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:11:01 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/28 17:32:52 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_destroy_images(t_game *game);

void	ft_free_all_allocated_memory(t_game *game)
{
	if (!game)
		return;
	ft_destroy_images(game);
	ft_free_map(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}

static void	ft_destroy_images(t_game *game)
{
	int	i;

	i = 0;
	
	void	*images[] = {
		game->wall.xpm_ptr,
		game->floor.xpm_ptr,
		game->coins.xpm_ptr,
		game->player_front.xpm_ptr,
		game->player_left.xpm_ptr,
		game->player_right.xpm_ptr,
		game->player_back.xpm_ptr,
		game->exit_closed.xpm_ptr,
		game->open_exit.xpm_ptr,
		NULL
	};
	
	while (images[i])
	{
		if (images[i])
			mlx_destroy_image(game->mlx_ptr, images[i]);
		free(images[i]);
		i++;
	}
}

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map.full)
		return;
	i = 0;
	while (i < game->map.rows)
		free(game->map.full[i++]);
	free(game->map.full);
}

void	ft_free_just_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->rows)
    {
        free(map->full[i]);
        i++;
    }
    free(map->full);
    free(map);
}

int ft_destroy_window(t_game *game)
{	
	if (!game)
		ft_free_all_allocated_memory(game);
    exit(0);
	return (0);
}
