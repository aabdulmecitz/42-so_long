/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:42:34 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/15 21:22:40 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int is_valid_position(t_game *game, int x, int y);

void ft_enemy_movement(t_game *game, t_enemy *enemy)
{
    int new_x;
    int new_y;

    new_x = enemy->x;
    new_y = enemy->y;
    if (enemy->dir == BACK)
        new_y--;
    else if (enemy->dir == FRONT)
        new_y++;
    else if (enemy->dir == RIGHT)
        new_x++;
    else if (enemy->dir == LEFT)
        new_x--;
    printf("Enemy moving from (%d, %d) to (%d, %d)\n", enemy->x, enemy->y, new_x, new_y);

    if (is_valid_position(game, new_x, new_y))
    {
        game->map.full[enemy->y][enemy->x] = FLOOR;
        enemy->x = new_x;
        enemy->y = new_y;
        game->map.full[new_y][new_x] = WANDER_ENEMY;
    }
    else
    {
        enemy->dir = rand() % 4;
        if (enemy->dir == 0)
            enemy->dir = BACK;
        else if (enemy->dir == 1)
            enemy->dir = FRONT;
        else if (enemy->dir == 2)
            enemy->dir = LEFT;
        else
            enemy->dir = RIGHT;
    }
}


int is_valid_position(t_game *game, int x, int y)
{
    if (x < 0 || x >= game->map.columns || y < 0 || y >= game->map.rows)
        return 0;
    if (game->map.full[y][x] == WALL || game->map.full[y][x] == STAT_ENEMY || 
        game->map.full[y][x] == WANDER_ENEMY || game->map.full[y][x] == COINS ||
        game->map.full[y][x] == MAP_EXIT)
        return 0;
    return 1;
}

void ft_update_enemies(t_game *game)
{
    t_enemy *current;

    current = game->enemy;
    while (current)
    {
        printf("Enemy: x: %d, y: %d\n", current->x, current->y);
        if (game->game_num % 15 == 0)
        {
            ft_enemy_movement(game, current);
            /* code */
        }
        
        current = current->next;
    }
    printf("===========================\n");
}




