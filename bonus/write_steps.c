/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:52:57 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/16 00:11:55 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    write_steps(t_game *game, int x, int y)
{
    mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, "Movements: ");
    mlx_string_put(game->mlx_ptr, game->win_ptr, x + 64, y, 0xFFFFFF, ft_itoa(game->movements));
}