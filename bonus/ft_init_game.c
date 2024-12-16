/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:15:50 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/16 18:42:17 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_init_game(t_game *game);
void ft_init_mlx(t_game *game);
void ft_init_sprites(t_game *game);

void	ft_init_game(t_game *game)
{
    game->game_num = 0;
    game->map.coins = 0;
    game->map.exit = 0;
    game->map.players = 0;
    game->movements = 0;
    game->enemy_k_num = 0;
    game->enemy_x_num = 0;
    game->enemy = NULL;
    game->wall = NULL;
    game->floor = NULL;
    game->coins = NULL;
    game->player_front = NULL;
    game->player_left = NULL;
    game->player_right = NULL;
    game->player_back = NULL;
    game->open_exit = NULL;
    game->exit_closed = NULL;
    game->enemy_x = NULL;
    game->enemy_k = NULL;
    game->map.columns = ft_strlen(game->map.full[0]) - 1;
    while (game->map.full[game->map.rows])
        game->map.rows++;
    game->player_direction = FRONT;
    ft_init_mlx(game);
    ft_init_sprites(game);
    ft_printf(GREEN"Game initialization successful!\n"RESET);
}

void ft_init_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        ft_error_msg("Couldn't find mlx pointer. Try it using a VNC.", game);
    game->win_ptr = mlx_new_window(
        game->mlx_ptr,
        (game->map.columns + 1) * IMG_WIDTH,
        (game->map.rows + 2) * IMG_HEIGHT,
        "so_long"
    );
    if (!game->win_ptr)
    {
        free(game->mlx_ptr);
        ft_error_msg("Couldn't create the Window.", game);
    }
}

void ft_load_sprite(t_image *sprite, void *mlx, char *path, t_game *game)
{
    if (!sprite)
        ft_error_msg("Sprite pointer is NULL.", game);

    sprite->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite->x, &sprite->y);
    ft_printf(CYAN"Loading sprite from path: %s\n"RESET, path);

    if (!sprite->xpm_ptr)
    {
        ft_printf(RED"Failed to load sprite: %s\n"RESET, path);
        ft_error_msg("Couldn't find a sprite. Does it exist?", game);
    }
}


void ft_init_sprites(t_game *game)
{
    void *mlx = game->mlx_ptr;

    // Bellek ayır
    game->wall = malloc(sizeof(t_image));
    game->floor = malloc(sizeof(t_image));
    game->coins = malloc(sizeof(t_image));
    game->player_front = malloc(sizeof(t_image));
    game->player_left = malloc(sizeof(t_image));
    game->player_right = malloc(sizeof(t_image));
    game->player_back = malloc(sizeof(t_image));
    game->open_exit = malloc(sizeof(t_image));
    game->exit_closed = malloc(sizeof(t_image));
    game->enemy_x = malloc(sizeof(t_image));
    game->enemy_k = malloc(sizeof(t_image));

    // NULL kontrolü
    if (!game->wall || !game->floor || !game->coins ||
        !game->player_front || !game->player_left || !game->player_right ||
        !game->player_back || !game->open_exit || !game->exit_closed ||
        !game->enemy_x || !game->enemy_k)
    {
        ft_error_msg("Memory allocation failed for one of the sprites.", game);
    }

    // Sprite'ları yükle
    ft_load_sprite(game->wall, mlx, WALL_XPM, game);
    ft_load_sprite(game->floor, mlx, FLOOR_XPM, game);
    ft_load_sprite(game->coins, mlx, COINS_XPM, game);
    ft_load_sprite(game->player_front, mlx, PLAYER_FRONT_XPM, game);
    ft_load_sprite(game->player_left, mlx, PLAYER_LEFT_XPM, game);
    ft_load_sprite(game->player_right, mlx, PLAYER_RIGHT_XPM, game);
    ft_load_sprite(game->player_back, mlx, PLAYER_BACK_XPM, game);
    ft_load_sprite(game->open_exit, mlx, OPEN_EXIT_XPM, game);
    ft_load_sprite(game->exit_closed, mlx, EXIT_CLOSED_XPM, game);
    ft_load_sprite(game->enemy_x, mlx, WANDER_ENEMY_XPM, game);
    ft_load_sprite(game->enemy_k, mlx, STAT_ENEMY_XPM, game);
}
