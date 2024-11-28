/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:15:50 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/28 20:16:14 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init_game(t_game *game);
void ft_init_vars(t_game *game);
void ft_init_mlx(t_game *game);
void ft_init_sprites(t_game *game);
t_image *ft_new_sprite(void *mlx, char *path, t_game *game);

void	ft_init_game(t_game *game)
{
    ft_init_vars(game);
    ft_init_mlx(game);
    ft_init_sprites(game);
    ft_printf(GREEN"Game initialization successful!\n"RESET);
}

void ft_init_vars(t_game *game)
{
    game->map.coins = 0;
    game->map.exit = 0;
    game->map.players = 0;
    game->movements = 0;
    game->map.columns = ft_strlen(game->map.full[0]) - 1;
    while (game->map.full[game->map.rows])
        game->map.rows++;
    game->player_direction = FRONT;
}

void ft_init_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        ft_error_msg("Couldn't find mlx pointer. Try it using a VNC.", game);
    game->win_ptr = mlx_new_window(
        game->mlx_ptr,
        (game->map.columns + 1) * IMG_WIDTH,
        game->map.rows * IMG_HEIGHT,
        "so_long"
    );
    if (!game->win_ptr)
    {
        free(game->mlx_ptr);
        ft_error_msg("Couldn't create the Window.", game);
    }
}

void ft_init_sprites(t_game *game)
{
    void *mlx = game->mlx_ptr;

    game->wall = *ft_new_sprite(mlx, WALL_XPM, game); 
    game->floor = *ft_new_sprite(mlx, FLOOR_XPM, game);
    game->coins = *ft_new_sprite(mlx, COINS_XPM, game);
    game->player_front = *ft_new_sprite(mlx, PLAYER_FRONT_XPM, game);
    game->player_left = *ft_new_sprite(mlx, PLAYER_LEFT_XPM, game);
    game->player_right = *ft_new_sprite(mlx, PLAYER_RIGHT_XPM, game);
    game->player_back = *ft_new_sprite(mlx, PLAYER_BACK_XPM, game);
    game->open_exit = *ft_new_sprite(mlx, OPEN_EXIT_XPM, game);
    game->exit_closed = *ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
    
}


t_image *ft_new_sprite(void *mlx, char *path, t_game *game)
{
    t_image *sprite;

    sprite = malloc(sizeof(t_image));
    if (!sprite)
        ft_error_msg("Memory allocation failed for sprite.", game);
    sprite->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite->x, &sprite->y);
    ft_printf(CYAN"Loading sprite from path: %s\n"RESET, path);
    if (!sprite->xpm_ptr)
    {
        ft_printf(RED"Failed to load sprite: %s\n"RESET, path);
        free(sprite);
        ft_error_msg("Couldn't find a sprite. Does it exist?", game);
    }
    free(sprite);
    return sprite;
}




