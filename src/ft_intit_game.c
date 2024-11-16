/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intit_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:30:15 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/16 07:25:49 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

void ft_init_game(t_game *game, char *argv)
{
    int w = IMG_WIDTH;
    int h = IMG_HEIGHT;

    // MLX Başlat
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr) {
        ft_error_msg("Something gone wrong! MLX couldn't start!", game);
    }

    // Pencere Başlat
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_W, WIN_H, "Valhalla");
    if (!game->win_ptr) {
        ft_error_msg("Something gone wrong! WIN couldn't start!", game);
    }

    // Harita Başlat
    ft_init_map(game, argv);
    if (!game->map.full || !game->map.full[0]) {
        ft_error_msg("Map data is not properly initialized!", game);
    }
    game->map.columns = ft_strlen(game->map.full[0]) - 1;
    game->map.coins = 0;
    game->map.exit = 0;
    game->map.players = 0;

    // Texture Yükle
    game->coins.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/coin.xpm", &w, &h);
    if (!game->coins.xpm_ptr) {
        ft_error_msg("Failed to load coin texture!", game);
    }

    game->wall.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/techwall.xpm", &w, &h);
    if (!game->wall.xpm_ptr) {
        ft_error_msg("Failed to load wall texture!", game);
    }

    game->player_front.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/player.xpm", &w, &h);
    if (!game->player_front.xpm_ptr) {
        ft_error_msg("Failed to load player texture!", game);
    }

    game->exit_closed.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/closed_door.xpm", &w, &h);
    if (!game->exit_closed.xpm_ptr) {
        ft_error_msg("Failed to load closed door texture!", game);
    }

    game->open_exit.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/opened_door.xpm", &w, &h);
    if (!game->open_exit.xpm_ptr) {
        ft_error_msg("Failed to load opened door texture!", game);
    }

    // Pencere Kapama Kancası
    mlx_mouse_show(game->mlx_ptr, game->win_ptr);
    mlx_hook(game->win_ptr, 17, 0, close_window, NULL);

    game->movements = 0;
    game->player_sprite = RIGHT;
}
