/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:52:57 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/21 16:33:45 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	write_steps(t_game *game, int x, int y)
{
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 64, y, 0xFFFFFF, \
			ft_itoa(game->movements));
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, "Movements: ");
}
