/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:39:19 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/16 23:36:00 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*void init_coin_animation(t_game *game)
    {
        char *coin_frames[] = {
            "assets/sprites/coin/coin1.xpm",
            "assets/sprites/coin/coin2.xpm",
            "assets/sprites/coin/coin3.xpm",
            "assets/sprites/coin/coin4.xpm",
            NULL
        };

        int i = 0;
        t_image *new_coin;
        t_image *last_coin;

        while (coin_frames[i] != NULL)
        {
            new_coin = malloc(sizeof(t_image));
            if (!new_coin)
                ft_error_msg("Memory allocation failed for coin node.", game);

            ft_load_sprite(new_coin, game->mlx_ptr, coin_frames[i], game);
            
            if (game->coins == NULL)
            {
                game->coins = new_coin;
            }
            else
            {
                last_coin = game->coins;
                while (last_coin->next != NULL)
                {
                    last_coin = last_coin->next;
                }
                last_coin->next = new_coin;
            }

            new_coin->next = NULL;
            i++;
        }
    }

void update_coin_animation(t_game *game)
{
    static time_t last_update_time = 0;
    time_t current_time = time(NULL);
    t_image *current_coin;

    if (difftime(current_time, last_update_time) < 0.1)
        return;

    current_coin = game->coins;
    if (current_coin) 
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current_coin->xpm_ptr, 100, 100);

        game->coins = current_coin->next;
        if (!game->coins)
            game->coins = current_coin;
    }

    last_update_time = current_time;
}

void clear_coin_animation(t_game *game)
{
    t_image *current;
    t_image *next;

    current = game->coins;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    game->coins = NULL;
}*/

