/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:39:02 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/23 07:14:09 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    remove_carriage_return(char *str)
{
    char    *src;
    char    *dst;

    src = str;
    dst = str;
    while (*src != '\0')
    {
        if (*src != '\t')
        {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

// void replace_newline_with_null(char **words)
// {
//     int i;
//     int len;

//     i = 0;
//     while (words[i])
//     {
//         len = ft_strlen(words[i]);
//         if (words[i][len - 1] == '\n')
//             words[i][len - 1] = '\0';
//         i++;
//     }
// }

// void print_split_result(char **split_res)
// {
//     int i = 0;
//     while (split_res[i])
//     {
//         printf("Word %d: '%s'\n", i, split_res[i]);
//         i++;
//     }
// }

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
		printf(CYAN"%s|len : %d|\n"RESET, line_temp, (int)ft_strlen(line_temp));
		if (line_temp == NULL)
			break ;
		map_temp = ft_strjoin(map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');

	//print_split_result(game->map.full);
	game->map_alloc = true;
	free(map_temp);
}
