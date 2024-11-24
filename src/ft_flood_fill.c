/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:33:43 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/24 22:13:19 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void flood_fill(t_game *game, int x, int y, int *collected)
{
    // Harita sınırlarını kontrol et
    if (x < 0 || x >= game->map.columns || y < 0 || y >= game->map.rows || 
        game->map.full[y][x] == WALL || game->map.full[y][x] == 'V')
        return;
    
    // Koleksiyonları topla
    if (game->map.full[y][x] == COINS)
        (*collected)++;

    // Bu hücreyi ziyaret edilmiş olarak işaretle
    game->map.full[y][x] = 'V';

    // 4 yönü kontrol et
    flood_fill(game, x + 1, y, collected);  // Sağ
    flood_fill(game, x - 1, y, collected);  // Sol
    flood_fill(game, x, y + 1, collected);  // Aşağı
    flood_fill(game, x, y - 1, collected);  // Yukarı
}

static int ft_check_all_collectables(t_game *game)
{
    int collected = 0;
    int collectable_count = 0;
    int x = 0;
    int y = 0;

    // Haritayı tarayarak collectable (COINS) ve player'ı say
    while (y < game->map.rows)
    {
        x = 0;
        while (x < game->map.columns)
        {
            if (game->map.full[y][x] == COINS)
                collectable_count++;
            x++;
        }
        y++;
    }

    // Player'ı bul ve flood fill işlemi başlat
    y = 0;
    while (y < game->map.rows)
    {
        x = 0;
        while (x < game->map.columns)
        {
            if (game->map.full[y][x] == PLAYER)
            {
                flood_fill(game, x, y, &collected);  // Player'ın bulunduğu yerden flood fill başlat
                break;  // Flood fill başlatıldı, bu yüzden döngüyü kır
            }
            x++;
        }
        if (x < game->map.columns && game->map.full[y][x] == PLAYER)
            break;
        y++;
    }

    // Tüm koleksiyonların toplandığını kontrol et
    return collected == collectable_count;
}


void    check_as_a_hero(t_game *game)
{
    if (ft_check_all_collectables(game))
        ft_printf(GREEN"Passed from flood fill\n"RESET);
    else
        ft_error_msg("All of coins cant collectible.", game);
}

