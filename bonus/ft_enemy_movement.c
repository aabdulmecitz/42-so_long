/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:42:34 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/21 17:52:13 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy(t_game *game, t_enemy *enemy, int new_x, int new_y);

int	is_valid_position(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.columns || y < 0 || y >= game->map.rows)
		return (0);
	if (game->map.full[y][x] == WALL || game->map.full[y][x] == STAT_ENEMY ||
		game->map.full[y][x] == WANDER_ENEMY || game->map.full[y][x] == COINS ||
		game->map.full[y][x] == MAP_EXIT)
		return (0);
	return (1);
}

void	ft_enemy_movement(t_game *game, t_enemy *enemy)
{
	static clock_t	last_time = 0;
	clock_t			current_time;
	double			elapsed_time;

	int		new_x;
	int		new_y;

	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 10000.0;

	if (elapsed_time >= DELAY)
	{
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
		move_enemy(game, enemy, new_x, new_y);
		enemy->last_move_time = current_time;
		last_time = current_time;
	}
}

void	move_enemy(t_game *game, t_enemy *enemy, int new_x, int new_y)
{
	if (is_valid_position(game, new_x, new_y))
	{
		if (game->map.full[new_y][new_x] == PLAYER)
		{
			ft_failed_msg();
			ft_destroy_window(game);
		}
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

void	ft_handle_enemies(t_game *game)
{
	t_enemy	*current;

	current = game->enemy;
	while (current)
	{
		ft_enemy_movement(game, current);
		current = current->next;
	}
}
