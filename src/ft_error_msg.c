/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:50:53 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/15 04:10:16 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_error_msg(char *msg, t_game *game)
{
    if (game->map_alloc == 1)
        ft_free_map(game);
    free (game);
    ft_printf(RED"ERROR:\n%s"RESET, msg);
    exit(EXIT_FAILURE);
}