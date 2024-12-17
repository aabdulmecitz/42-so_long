/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 05:38:38 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/17 03:55:36 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    ft_paint_texture(t_game *game, int x, int y);

int ft_render_frame(t_game *game)
{
    int x;
    int y;

    ft_handle_enemies(game);
    y = 0;
    while (y < game->map.rows + 2)
    {
        x = 0;
        while (x < game->map.columns)
        {
            if (y < game->map.rows)
                ft_paint_texture(game, x, y);
            else
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
            x++;
        }
        y++;
    }
    write_steps(game, 32, (game->map.rows + 1) * IMG_HEIGHT);

    
    return (0);
}

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
void ft_paint_coin(t_game *game, int x, int y) {
    t_image *current_coin_frame = get_current_coin_frame(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current_coin_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void    ft_paint_texture(t_game *game, int x, int y)
{
    if (game->map.full[y][x] == WALL)
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
    else if (game->map.full[y][x] == FLOOR)
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
    else if (game->map.full[y][x] == COINS)
        ft_paint_coin(game, x, y);
    else if (game->map.full[y][x] == WANDER_ENEMY)
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->enemy_x->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
    else if (game->map.full[y][x] == STAT_ENEMY)
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->enemy_k->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
    else if (game->map.full[y][x] == PLAYER)
    {
        if (game->player_direction == FRONT)
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_front->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
        else if (game->player_direction == BACK)
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_back->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
        else if (game->player_direction == LEFT)
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_left->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
        else if (game->player_direction == RIGHT)
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_right->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
    }
    else if (game->map.full[y][x] == MAP_EXIT)
    {
        if (game->map.coins == 0)
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->open_exit->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
        else
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_closed->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
    }
}
