/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:59:37 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/30 18:03:23 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_move_enemy_x(t_game *game)
{
    int new_x;
    int new_y;
    
    new_y = game->enemy_x.pos.y;
    new_x = game->enemy_x.pos.x;
    if (game->enemy_x.dir == RIGHT)
        new_x++;
    else if (game->enemy_x.dir == LEFT)
        new_x--;
    else if (game->enemy_x.dir == BACK)
        new_y--;
    else if (game->enemy_x.dir == FRONT)
        new_y++;
    if (game->map.full[new_y][new_x] == FLOOR)
    {
        game->enemy_x.pos.x = new_x;
        game->enemy_x.pos.y = new_y;
    }
    else
    {
        if (game->enemy_x.dir == RIGHT) game->enemy_x.dir = FRONT;
        else if (game->enemy_x.dir == FRONT) game->enemy_x.dir = LEFT;
        else if (game->enemy_x.dir == LEFT) game->enemy_x.dir = BACK;
        else if (game->enemy_x.dir == BACK) game->enemy_x.dir = RIGHT;
    }
}

void ft_check_collision_fixed_enemy(t_game *game)
{
    if (game->map.player.x == game->enemy_k.pos.x &&
        game->map.player.y == game->enemy_k.pos.y)
    {
        ft_printf(RED"Game Over! You collided with a fixed enemy (K).\n"RESET);
        ft_destroy_window(game);
    }
}

void ft_check_collision_wandering_enemy(t_game *game)
{
    if (game->map.player.x == game->enemy_x.pos.x &&
        game->map.player.y == game->enemy_x.pos.y)
    {
        ft_printf(RED"Game Over! You collided with a wandering enemy (X).\n"RESET);
        ft_destroy_window(game);
    }
}

