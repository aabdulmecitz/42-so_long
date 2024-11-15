/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:19:00 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/16 02:16:08 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_empty_line(char *map, t_game *game);

void ft_init_map(t_game *game, char const *argv)
{
    char *map_tmp;
    char *line_tmp;
    int fd;
    
    fd = open(argv, O_RDWR, 0777);
    map_tmp = ft_strdup("");
    if(fd < 0)
        ft_error_msg("Something gone wrong about file descriptor", game);
    while (1)
    {
        line_tmp = get_next_line(fd);
        if (line_tmp == NULL)
            break;
        map_tmp = ft_strjoin(map_tmp, line_tmp);
        free(line_tmp);
        game->map.rows++;
    }
    close(fd);
    ft_check_empty_line(map_tmp, game);
    game->map.full = ft_split(map_tmp, '\n');
    game->map_alloc = true;
    free(map_tmp);
}

void ft_check_empty_line(char *map, t_game *game)
{
    int i;

    i = 0;
    if (map[0] == '\n')
    {
        free(map);
        ft_error_msg("The map has empty line at start", game);
    }
    else if (map[ft_strlen(map) - 1] == '\n')
    {
        free(map);
        ft_error_msg("The map has empty line at finish", game);
    }
    while (map[i + 1])
    {
        if (map[i] == '\n' && map[i + 1] == '\n')
        {
            free(map);
            ft_error_msg("That is a problem man. This map include empt line.", game);
        }
        i++;
    }
}