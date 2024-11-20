/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intit_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:30:15 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/19 21:42:22 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}
// void    ft_init_player_sprite(t_game game, int frame)
// {
//     int x;
//     int y;
    
//     x = (frame )
// }

void ft_init_game(t_game *game, char *argv)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
    {
        ft_error_msg("MLX initialization failed", game);
        return;
    }

    game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "So Long");
    if (!game->win_ptr)
    {
        ft_error_msg("Window creation failed", game);
        return;
    }

    game->movements = 0;
    game->player_sprite = 0;

    ft_init_map(game, argv);

    game->undefined_image = (t_image){NULL, 0, 0};
    game->wall = (t_image){NULL, 0, 0};
    game->floor = (t_image){NULL, 0, 0};
    game->coins = (t_image){NULL, 0, 0};
    game->open_exit = (t_image){NULL, 0, 0};
    game->exit_closed = (t_image){NULL, 0, 0};
    game->player_front = (t_image){NULL, 0, 0};
    game->player_left = (t_image){NULL, 0, 0};
    game->player_right = (t_image){NULL, 0, 0};
    game->player_back = (t_image){NULL, 0, 0};

    game->map.full = NULL;
    game->map.rows = 0;
    game->map.columns = 0;
    game->map.coins = 0;
    game->map.exit = 0;
    game->map.players = 0;
    game->map.player = (t_positon){-1, -1};

    game->map_alloc = false;
    
    // int w = IMG_WIDTH;
    // int h = IMG_HEIGHT;
        
    // // MLX Başlat
    // game->mlx_ptr = mlx_init();
    // if (!game->mlx_ptr) {
    //     ft_printf("Something gone wrong! MLX couldn't start!");
    // }

    // // Pencere Başlat
    // game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_W, WIN_H, "Valhalla");
    // if (!game->win_ptr) {
    //     ft_printf("Something gone wrong! WIN couldn't start!");
    // }

    // // Harita Başlat
    // ft_init_map(game, argv);
    // if (!game->map.full || !game->map.full[0]) {
    //     ft_printf("Map data is not properly initialized!");
    // }
    // game->map.columns = ft_strlen(game->map.full[0]) - 1;
    // game->map.coins = 0;
    // game->map.exit = 0;
    // game->map.players = 0;

    // // Texture Yükle

    // game->wall.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/techwall.xpm", &w, &h);
    // if (!game->wall.xpm_ptr) {
    //     ft_printf("Failed to load wall texture!");
    // }
    
    // game->coins.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/coin.xpm", &w, &h);
    // if (!game->coins.xpm_ptr) {
    //     ft_printf("Failed to load coin texture!");
    // }

    // game->player_front.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/player.xpm", &w, &h);
    // if (!game->player_front.xpm_ptr) {
    //     ft_printf("Failed to load player texture!");
    // }

    // game->exit_closed.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/closed_door.xpm", &w, &h);
    // if (!game->exit_closed.xpm_ptr) {
    //     ft_printf("Failed to load closed door texture!");
    // }

    // game->open_exit.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/opened_door.xpm", &w, &h);
    // if (!game->open_exit.xpm_ptr) {
    //     ft_printf("Failed to load opened door texture!");
    // }

    // // Pencere Kapama Kancası
    // mlx_mouse_show(game->mlx_ptr, game->win_ptr);
    // mlx_hook(game->win_ptr, 17, 0, close_window, NULL);

    // game->movements = 0;
    // game->player_sprite = RIGHT;
}
