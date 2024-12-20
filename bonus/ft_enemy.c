/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:59:37 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/21 00:26:48 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_enemy_value(t_enemy *new_enemy, t_game *game, int x, int y);

void	ft_init_enemy(t_game *game)
{
	int		x;
	int		y;
	t_enemy	*new_enemy;

	game->enemy = NULL;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->enemy_x_num == 0)
				return ;
			if (game->map.full[y][x] == WANDER_ENEMY)
			{
				new_enemy = (t_enemy *)malloc(sizeof(t_enemy));
				if (!new_enemy)
					return ;
				ft_init_enemy_value(new_enemy, game, x, y);
			}
			x++;
		}
		y++;
	}
}

void	ft_init_enemy_value(t_enemy *new_enemy, t_game *game, int x, int y)
{
	new_enemy->x = x;
	new_enemy->y = y;
	new_enemy->dir = rand() % 4;
	new_enemy->last_move_time = time(NULL);
	new_enemy->next = game->enemy;
	game->enemy = new_enemy;
	game->enemy_x_num--;
}
// IF ENEMY SEE THE PLAYER YOU WILL LOSE
