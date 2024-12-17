/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:39:19 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/17 03:57:43 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_image *get_current_coin_frame(t_game *game)
{
    static clock_t last_time = 0;
    static t_image *current_frame = NULL;
    clock_t current_time;
    double elapsed_time;

    current_time = clock();
    elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 1500.0;

    if (current_frame == NULL)
        current_frame = game->coins;

    if (elapsed_time >= delay)
    {
        current_frame = current_frame->next;
        if (current_frame == NULL)
            current_frame = game->coins;
        last_time = current_time;
    }
    return current_frame;
}
void ft_paint_coin_with_animation(t_game *game, int x, int y)
{
    t_image *current_coin_frame = get_current_coin_frame(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current_coin_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}