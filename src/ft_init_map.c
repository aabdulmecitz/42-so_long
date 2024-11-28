/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:02 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/28 15:20:46 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_carriage_return(char *line);
void    ft_check_for_empty_line(char *map, t_game *game);

void	ft_init_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldn't be opened. Does the Map exist?", game);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		//remove_carriage_return(line_temp); // windowsta calistirirken bunu kullanmak lazim.
		map_temp = ft_strjoin(map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);

	ft_check_for_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

void	remove_carriage_return(char *line)
{
    int start;
    int end;

	start = 0;
	end = ft_strlen(line) - 1;
    while (line[start] == '\r' || line[start] == '\n')
        start++;
    while (end >= 0 && (line[end] == '\r' || line[end] == '\n'))
	{
        line[end] = '\n';
		line[end + 1] = '\0';
        end--;
	}
    ft_memmove(line, line + start, end - start + 2);
}

void    ft_check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map.\
The map have an empty line right at the beginning.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free (map);
		ft_error_msg("Invalid map. \
The map have an empty line at the end.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid map. \
The map have an empty line at the middle.", game);
		}
		i++;
	}
}

