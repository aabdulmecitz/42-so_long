/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:35:58 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/16 17:17:12 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free_map(t_game *game)
{
    if (game->map.full)
    {
        for (int i = 0; i < game->map.rows; i++)
        {
            if (game->map.full[i])
                free(game->map.full[i]);
        }
        free(game->map.full);
        game->map.full = NULL;
    }

    if (game->mlx_ptr)
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    game->mlx_ptr = NULL;
    game->win_ptr = NULL;
}