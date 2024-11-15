/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command_line_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:45:25 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/15 05:11:26 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_command_line_args(int argc, char const *argv[], t_game *game)
{
    int map_len;
    
    if (argc < 2)
        ft_printf("Where is the map bro? Please Enter a map!");
    if (argc > 2)
        ft_printf("You entered alot of argument. You must enter one map file without game");
    map_len = ft_strlen(argv[1]);
    if (ft_strnstr(&argv[1], ".ber", map_len - 4))
        ft_printf("Map file is not valid. You can enter just .ber file.");
}