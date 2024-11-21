/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:22:29 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/21 16:28:50 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_validate_map(t_game *game)
{
    int i;
    int j;

    if (!game->map.full || !game->map.full[0])
        ft_error_msg("Harita yüklenemedi veya boş!", game);

    int row_length = ft_strlen(game->map.full[0]);
    for (i = 0; i < game->map.rows; i++)
    {
        if ((int)ft_strlen(game->map.full[i]) != row_length)
            ft_error_msg("Harita dikdörtgen değil!", game);
    }

    for (i = 0; i < game->map.rows; i++)
    {
        for (j = 0; j < game->map.columns; j++)
        {
            if ((i == 0 || i == game->map.rows - 1 || j == 0 || j == game->map.columns - 1)
                && game->map.full[i][j] != WALL)
                ft_error_msg("Harita çevresi tamamen duvarlarla kaplanmamış!", game);
        }
    }

    game->map.coins = 0;
    game->map.exit = 0;
    game->map.players = 0;

    for (i = 0; i < game->map.rows; i++)
    {
        for (j = 0; j < game->map.columns; j++)
        {
            char c = game->map.full[i][j];
            if (c == PLAYER)
            {
                game->map.players++;
                game->map.player.x = j;
                game->map.player.y = i;
            }
            else if (c == COINS)
                game->map.coins++;
            else if (c == MAP_EXIT)
                game->map.exit++;
            else if (c != WALL && c != FLOOR)
                ft_error_msg("Geçersiz karakter bulundu!", game);
        }
    }

    if (game->map.players != 1)
        ft_error_msg("Haritada tek bir oyuncu olmalı!", game);
    if (game->map.coins < 1)
        ft_error_msg("Haritada en az bir collectible olmalı!", game);
    if (game->map.exit < 1)
        ft_error_msg("Haritada en az bir çıkış noktası olmalı!", game);
}
