/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:59:37 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/03 22:59:14 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    ft_enemy(t_game *game)
{
    ft_init_enemy(game);
    
}

void    ft_init_enemy(t_game *game)
{
    if (game->enemy_k != 0)
    {
        game->enemy_k = malloc(sizeof(t_enemy));
        ft_load_sprite(&game->enemy_k->sprite, game->mlx_ptr, STAT_ENEMY_XPM, game);
        game->enemy_k->dir = IDLE;
    }
    if (game->enemy_x != 0)
        game->enemy_x = malloc(sizeof(t_enemy));
        ft_load_sprite(&game->enemy_k->sprite, game->mlx_ptr, STAT_ENEMY_XPM, game);
        game->enemy_x->dir = IDLE;
}
