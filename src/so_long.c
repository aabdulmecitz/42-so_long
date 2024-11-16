/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:00:21 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/16 07:02:57 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    t_game *game;

    game = malloc(sizeof(t_game));
    ft_check_command_line_args(argc, argv, game);
    ft_init_game(game, (char *)argv[1]);
    ft_draw_map(game);
    mlx_loop(game->mlx_ptr);
    return 0;   
}
