/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:00:21 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/16 02:23:55 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main(int argc, char const *argv[])
{
    t_game *game;

    game = malloc(sizeof(t_game));
    ft_check_command_line_args(argc, argv, game);
    ft_init_map(game, argv[1]);
    
    //===========================================================
    
    void *mlx;
    void *win;
    void *image;
    void *player;
    
    int h = 64;
    int w = 64;
    
    mlx = mlx_init();
    if (!mlx) {
        printf("MiniLibX başlatılamadı!\n");
        return 1;
    }

    win = mlx_new_window(mlx, 1920, 1080, "Midgard");
    if (!win) {
        printf("Pencere oluşturulamadi!\n");
        return 1;
    }

    mlx_mouse_show(mlx, win);
    mlx_hook(win, 17, 0, close_window, NULL);

    image = mlx_xpm_file_to_image(mlx, ".//textures/techwall.xpm", &w, &h);
    void *image2 = mlx_xpm_file_to_image(mlx, ".//textures/player.xpm", &w + 32 , &h + 32);
    
    if (!image) {
        printf("XPM dosyasi yüklenemedi!\n");
        return 1;
    }    
    player = mlx_xpm_file_to_image(mlx, "./textures/player.xpm", &w, &h);
    if (!player) {
        printf("XPM dosyasi yüklenemedi!\n");
        return 1;
    }
   
    mlx_put_image_to_window(mlx, win, image, 0, 0);
    mlx_put_image_to_window(mlx, win, image2, 32, 0);
    mlx_put_image_to_window(mlx, win, image, 32, 32);
    mlx_put_image_to_window(mlx, win, image, 32, 64);
    mlx_put_image_to_window(mlx, win, image, 64, 64);
    mlx_put_image_to_window(mlx, win, image, 64, 128);
    mlx_put_image_to_window(mlx, win, image, 64, 0);
    mlx_put_image_to_window(mlx, win, image, 96, 0);
    mlx_put_image_to_window(mlx, win, image, 128, 0);
    
    mlx_put_image_to_window(mlx, win, player, 64, 32);

    mlx_loop(mlx);
    //===========================================================
    return 0;   
}
