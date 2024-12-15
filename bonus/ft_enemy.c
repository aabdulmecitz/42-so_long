/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:59:37 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/15 21:57:07 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void ft_init_enemy(t_game *game)
{
    int x;
    int y;
    t_enemy *new_enemy;

    game->enemy = NULL;  // Düşmanları başlat
    y = 0;

    while (y < game->map.rows)
    {
        x = 0;
        while (x < game->map.columns)
        {
            if (game->enemy_x_num == 0)  // Eğer düşman sayısı sıfırsa, işlemi bitir
                return;
            if (game->map.full[y][x] == WANDER_ENEMY)
            {
                // Yeni düşmanı oluştur
                new_enemy = (t_enemy *)malloc(sizeof(t_enemy));
                if (!new_enemy)
                    return;  // Bellek hatası durumunda çıkış yap
                new_enemy->x = x;
                new_enemy->y = y;
                new_enemy->dir = rand() % 4;  // Düşman yönü rastgele belirle
                new_enemy->last_move_time = time(NULL);  // İlk hareket zamanını şu anki zaman olarak ayarla
                new_enemy->next = game->enemy;  // Mevcut düşmanların önüne ekle
                game->enemy = new_enemy;  // Listeyi güncelle
                game->enemy_x_num--;  // Düşman sayısını azalt
            }
            x++;
        }
        y++;
    }
}


// IF ENEMY SEE THE PLAYER YOU WILL LOSE 
