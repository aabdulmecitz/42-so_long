/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:00:21 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/21 21:05:35 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// int close_window(void *param)
// {
//     t_game *game = (t_game *)param;

//     printf("Pencere kapatılıyor...\n"); // Test amaçlı
//     if (game->win_ptr)
//     {
//         mlx_destroy_window(game->mlx_ptr, game->win_ptr);
//         game->win_ptr = NULL;
//     }
//     exit(0);
//     return (0);
// }

// int key_hook(int keycode, t_game *game)
// {
//     printf("Tuş basıldı: %d\n", keycode); // Test amaçlı
//     if (keycode == KEY_ESC || keycode == KEY_Q)
//         close_window(game);
//     return (0);
// }

int main(int argc, char const *argv[])
{
    t_game *game;
    void *image;
    int a;
    int b;

    // a = 32;
    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
        return (1);

    ft_check_command_line_args(argc, argv, game);
    ft_init_game(game);
    ft_printf("game initiated\n");
    ft_configure_game(game);
    ft_printf("game configured\n");
    ft_init_map(game, argv[1]);
    ft_printf("map initiated\n");
    ft_validate_map(game);
    image = mlx_xpm_file_to_image(game->mlx_ptr, "textures/techwall.xpm", &a, &b);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, 0, 0);
    // //ft_draw_map(game);
    ft_printf("map drawn\n");

    // Pencere kapatma ve tuş basma olaylarını yakalama
    // mlx_hook(game->win_ptr, 33, 1L << 17, close_window, game); // 33 -> DestroyNotify için
    // mlx_key_hook(game->win_ptr, key_hook, game);

    //mlx_loop(game->mlx_ptr);
    free(game);

    return 0;
}


