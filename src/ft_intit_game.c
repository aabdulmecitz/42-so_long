/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intit_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:30:15 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/20 16:43:22 by aozkaya          ###   ########.fr       */
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