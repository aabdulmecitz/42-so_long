/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:50:53 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/23 02:28:37 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error_msg(char *msg, t_game *game)
{
    if (game)
    {
        if (game->map_alloc)
            ft_free_map(game);

        if (game->wall.xpm_ptr)
            free(game->wall.xpm_ptr);

        free(game);
        game = NULL;
    }

    ft_printf(RED"ERROR:\n%s\n"RESET, msg);
    exit(EXIT_FAILURE);
}

