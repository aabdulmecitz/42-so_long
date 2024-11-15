/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:35:58 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/16 00:43:10 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_free_map(t_game *game)
{
    int i;
    
    i = 0;
    while (i < game->map.rows)
    {
        free(game->map.full[i]);
        i++;
    }
    free(game->map.full);
}