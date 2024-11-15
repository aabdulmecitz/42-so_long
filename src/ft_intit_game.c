/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intit_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:30:15 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/15 11:39:50 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init_game(t_game *game)
{
    game->map.coins = 0;
    game->map.exit = 0;
    game->map.players = 0;
    game->map.columns = ft_strlen(game->map.full[0] - 1);
    game->movements = 0;
    game->player_sprite = RIGHT;
}