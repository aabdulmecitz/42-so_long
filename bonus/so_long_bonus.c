/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:07 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:09:09 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_game(t_game *game)
{
	ft_free_all_allocated_memory(game);
	ft_printf(GREEN "Game closed successfully.\n" RESET);
	exit(0);
	return (0);
}

int	main(int argc, const char *argv[])
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error_msg("Memory allocation failed for game", game);
	ft_check_command_line_args(argc, argv, game);
	ft_init_map(game, (char *)argv[1]);
	ft_init_game(game);
	ft_check_map(game);
	ft_init_enemy(game);
	init_all_of_animations(game);
	ft_handle_enemies(game);
	mlx_loop_hook(game->mlx_ptr, ft_render_frame, game);
	ft_handle_buttons(game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
