/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:52:02 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/17 04:58:10 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    make_border(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < game->map.rows)
    {
        while (j < game->map.columns)
        {
            if (i == 0 || j == 0 || 
                i == game->map.rows-1 || j == game->map.columns-1)
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall->xpm_ptr, j * IMG_WIDTH, i * IMG_HEIGHT);
            j++;
        }
        i++;
    }
    
}

void    finish_screen(t_game *game, int is_succes)
{
    t_image *succes;
    t_image *fail;

    mlx_clear_window(game->mlx_ptr, game->win_ptr);
    make_border(game);
    succes->xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, 
        "../assets/sprites/finish_screen/succes.xpm", 96, 64);
    fail->xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, 
        "../assets/sprites/finish_screen/failed.xpm", 96, 64);
    if (is_succes)
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
            succes->xpm_ptr, ((game->map.columns - 3)/2) * IMG_WIDTH, 
            ((game->map.rows - 2)/2) * IMG_HEIGHT);
    }
    else if (is_succes == 0)
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
            fail->xpm_ptr, ((game->map.columns - 3)/2) * IMG_WIDTH, 
            ((game->map.rows - 2)/2) * IMG_HEIGHT);
    }
}
