/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:00:21 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/20 16:43:33 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    t_game *game;

    game = (t_game*)malloc(sizeof(t_game));
    if (!game) {
        printf("Error: Failed to allocate memory for game\n");
        return 1;
    }
    ft_init_game(game, (char *)argv[1]);
    ft_configure_game(game);
    ft_init_map(game, argv[1]);
    ft_draw_map(game);
    
    mlx_loop(game->mlx_ptr);
    return 0;
}