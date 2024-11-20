/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:19:00 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/19 16:03:17 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_count_coins(t_game *game);

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
            ft_error_msg("The map includes empty line.", game);
        }
        i++;
    }
}

void ft_init_map(t_game *game, char const *argv)
{
    char *map_tmp;
    char *line_tmp;
    int fd;
    
    fd = open(argv, O_RDONLY); // Dosya yalnızca okuma için açılmalı
    if (fd < 0)
        ft_error_msg("Something went wrong with file descriptor", game);

    map_tmp = ft_strdup("");
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
void ft_draw_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map.full && game->map.full[i])
    {
        j = 0;
        while (game->map.full[i][j])
        {
            if (game->map.full[i][j] == WALL)
            {
                if (game->wall.xpm_ptr)
                    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.xpm_ptr, game->wall.x * IMG_WIDTH * j, game->wall.y * IMG_HEIGHT * i);
            }
            else if (game->map.full[i][j] == '0')
            {
                if (game->floor.xpm_ptr)
                    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, game->floor.x * IMG_WIDTH * j, game->floor.y * IMG_HEIGHT * i);
            }
            else if (game->map.full[i][j] == 'C')
            {
                if (game->coins.xpm_ptr)
                    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->coins.xpm_ptr, game->coins.x * IMG_WIDTH * j, game->coins.y * IMG_HEIGHT * i);
            }
            else if (game->map.full[i][j] == 'P')
            {
                if (game->player_front.xpm_ptr)
                    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_front.xpm_ptr, game->player_front.x * IMG_WIDTH * j, game->player_front.y * IMG_HEIGHT * i);
            }
            else if (game->map.full[i][j] == 'E')
            {
                if (game->map.coins == ft_count_coins(game))
                {
                    if (game->open_exit.xpm_ptr)
                        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->open_exit.xpm_ptr, game->open_exit.x * IMG_WIDTH * j, game->open_exit.y * IMG_HEIGHT * i);
                }
                else
                {
                    if (game->exit_closed.xpm_ptr)
                        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_closed.xpm_ptr, game->exit_closed.x * IMG_WIDTH * j, game->exit_closed.y * IMG_HEIGHT * i);
                }
            }
            else
            {
                if (game->undefined_image.xpm_ptr)
                    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->undefined_image.xpm_ptr, game->undefined_image.x * IMG_WIDTH * j, game->undefined_image.y * IMG_HEIGHT * i);
            }
            j++;
        }
        i++;
    }
}

 
int ft_count_coins(t_game *game)
{
    int i;
    int j;
    int res;

    i = 0;
    res = 0;
    while (game->map.full[i])
    {
        j = 0;
        while (game->map.full[i][j])
        {
            if (game->map.full[i][j] == 'c')
                res++;
            j++;
        }
        i++;
    }
    return (res);
}
void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.xpm_ptr, column * sprite.x, line * sprite.y);
}
