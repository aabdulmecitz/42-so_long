/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:33:43 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/24 22:42:22 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void flood_fill(t_game *game, int x, int y, int *collected)
{
    if (x < 0 || x >= game->map.columns || y < 0 || y >= game->map.rows || 
        game->map.full[y][x] == WALL || game->map.full[y][x] == 'F')
        return;
    if (game->map.full[y][x] == COINS)
        (*collected)++;
    game->map.full[y][x] = 'F';
    flood_fill(game, x + 1, y, collected);
    flood_fill(game, x - 1, y, collected);
    flood_fill(game, x, y + 1, collected);
    flood_fill(game, x, y - 1, collected);
}

static int ft_check_all_collectables(t_game *game)
{
    int x;
    int y;
    int collected;
    int collectable_count;

    collectable_count = game->map.coins;
    collected = 0;
    y = 0;
    while (y < game->map.rows)
    {
        x = 0;
        while (x < game->map.columns)
        {
            if (game->map.full[y][x] == PLAYER)
            {
                flood_fill(game, x, y, &collected);
                break;
            }
            x++;
        }
        if (x < game->map.columns && game->map.full[y][x] == PLAYER)
            break;
        y++;
    }
    return collected == collectable_count;
}

void    check_as_a_hero(t_game *game)
{
    if (ft_check_all_collectables(game))
        ft_printf(GREEN"Passed from flood fill\n"RESET);
    else
        ft_error_msg("All of coins cant collectible.", game);
}

