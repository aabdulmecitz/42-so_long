/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:32:02 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/24 22:39:38 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_check_rectanglular(t_game *game);
void    ft_check_elements(t_game *game);
void    ft_element_counter(t_game *game);

void    ft_check_map(t_game *game)
{
    ft_check_rectanglular(game);
    
    printf(CYAN"***here***\n"RESET);

    ft_check_elements(game);
    check_as_a_hero(game);
    ft_printf("rows %d, columns %d\n", game->map.rows, game->map.columns);
    ft_printf(GREEN"Map validation passed!\n"RESET);
}

void    ft_check_rectanglular(t_game *game)
{
    int i;
    int first_row_len;
    int current_row_len;

    if (game->map.rows == 0)
        return;
    first_row_len = (int)ft_strlen(game->map.full[0]);
    i = 1;
    while (i < game->map.rows)
    {
        current_row_len = (int)ft_strlen(game->map.full[i]);
        if (current_row_len != first_row_len)
        {
            ft_printf(RED "%s , current row len: %d , first row len: %d\n" RESET, game->map.full[i], current_row_len, first_row_len);
            ft_error_msg("Map is not rectangular!", game);
            return;
        }
        i++;
    }
    game->map.columns++;
    ft_printf(GREEN "Map is rectangular!\n" RESET);
}

void    ft_check_elements(t_game *game)
{
    ft_element_counter(game);
    if (game->map.players != 1)
        ft_error_msg("Map must contain exactly one starting position ('P')", game);
    if (game->map.exit != 1)
        ft_error_msg("Map must contain exactly one exit ('E')", game);
    if (game->map.coins < 1)
        ft_error_msg("Map must contain at least one collectible ('C')", game);
}

void    ft_element_counter(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map.rows)
    {
		ft_printf(CYAN"|%s| size: %d|\n" RESET, game->map.full[y], (int)ft_strlen(game->map.full[y]));
        x = 0;
        while (x < game->map.columns)
        {
            if ((y == 0 || y == game->map.rows - 1 || x == 0 || x == game->map.columns - 1) && game->map.full[y][x] != WALL)
                ft_error_msg("Invalid Map.", game);
            if (game->map.full[y][x] == PLAYER)
                game->map.players++;
            else if (game->map.full[y][x] == MAP_EXIT)
                game->map.exit++;
            else if (game->map.full[y][x] == COINS)
                game->map.coins++;
            else if (game->map.full[y][x] != WALL && game->map.full[y][x] != FLOOR &&
                game->map.full[y][x] != PLAYER && game->map.full[y][x] != MAP_EXIT && game->map.full[y][x] != COINS)
                ft_error_msg("Invalid character in map", game);
            x++;
        }
        y++;
    }
}
