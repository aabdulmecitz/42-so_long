/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:15 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:09:16 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	write_steps(t_game *game, int x, int y)
{
	char	*movement;

	movement = ft_itoa(game->movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 64, y, 0xFFFFFF, movement);
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, "Movements: ");
	free(movement);
}
