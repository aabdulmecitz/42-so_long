/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:19:00 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/21 20:28:11 by aabdulmecit      ###   ########.fr       */
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
    
    fd = open(argv, O_RDONLY);
    if (fd < 0)
        ft_error_msg("Something went wrong with file descriptor", game);
    map_tmp = ft_strdup("");
    game->map.rows = 0;
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
    int x;
    int y;

    y = 0;
    while (y < game->map.rows)
    { 
        x = 0;
        while (x < game->map.columns)
        {
            ft_render_sprite(game, x, y);
            x++;
        }
        printf("\n");
        y++;
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
void    ft_render_sprite(t_game *game, int x, int y)
{
    /*char param; 
    param = game->map.full[y][x];*/
    printf("%d, %d, %s\n", x, y, (char *)game->wall.xpm_ptr);
    //printf ("%p, %p, %p %d, %d\n", game->mlx_ptr, game->win_ptr, mlx_xpm_file_to_image(game->mlx_ptr, game->wall.xpm_ptr, 0,0), x, y);
   /* if (param == WALL)
        mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, mlx_xpm_file_to_image(game->mlx_ptr, "../textures/techwall.xpm", 0,0), x, y);
    */
}
