/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intit_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:30:15 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/21 16:13:58 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

void ft_init_game(t_game *game)
{
    if (!game)
    {
        printf("Error: Failed to allocate memory for game\n");
        return;
    }
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
    {
        ft_error_msg("MLX initialization failed", game);
        return;
    }
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_W, WIN_H, "So Long");
    if (!game->win_ptr)
    {
        ft_error_msg("Window creation failed", game);
        return;
    }
    game->movements = 0;
    game->player_sprite = 0;
    game->movements = 0;
    game->player_sprite = FRONT;
    game->map.full = NULL;
    game->map.rows = 0;
    game->map.columns = 0;
    game->map.coins = 0;
    game->map.exit = 0;
    game->map.players = 0;
    game->map.player.x = 0;
    game->map.player.y = 0;
    game->map_alloc = false;
    game->undefined_image.xpm_ptr = NULL;
    game->undefined_image.x = 0;
    game->undefined_image.y = 0;
    game->wall.xpm_ptr = NULL;
    game->wall.x = 0;
    game->wall.y = 0;
    game->floor.xpm_ptr = NULL;
    game->floor.x = 0;
    game->floor.y = 0;
    game->coins.xpm_ptr = NULL;
    game->coins.x = 0;
    game->coins.y = 0;
    game->open_exit.xpm_ptr = NULL;
    game->open_exit.x = 0;
    game->open_exit.y = 0;
    game->exit_closed.xpm_ptr = NULL;
    game->exit_closed.x = 0;
    game->exit_closed.y = 0;
    game->player_front.xpm_ptr = NULL;
    game->player_front.x = 0;
    game->player_front.y = 0;
    game->player_left.xpm_ptr = NULL;
    game->player_left.x = 0;
    game->player_left.y = 0;
    game->player_right.xpm_ptr = NULL;
    game->player_right.x = 0;
    game->player_right.y = 0;
    game->player_back.xpm_ptr = NULL;
    game->player_back.x = 0;
    game->player_back.y = 0;
}

void    ft_configure_game(t_game *game)
{
    game->undefined_image = (t_image){"../textures/lava.xpm", 0, 0};
    game->wall = (t_image){"../textures/wall.xpm", 0, 0};
    game->floor = (t_image){"../textures/way.xpm", 0, 0};
    game->coins = (t_image){"../textures/coin.xpm", 0, 0};
    game->open_exit = (t_image){"../textures/opened_door.xpm", 0, 0};
    game->exit_closed = (t_image){"../textures/closed_door.xpm", 0, 0};
    game->player_front = (t_image){"../textures/player.xpm", 0, 0};
    game->player_left = (t_image){"../textures/wall.xpm", 0, 0};
    game->player_right = (t_image){"../textures/wall.xpm", 0, 0};
    game->player_back = (t_image){"../textures/wall.xpm", 0, 0};
}


