/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:50:53 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/19 02:11:43 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_msg(char *msg, t_game *game)
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
	ft_printf(RED "ERROR:\n%s\n" RESET, msg);
	exit(EXIT_FAILURE);
}

void	ft_congrats_message(void)
{
	ft_printf(GREEN "\n");
	ft_printf(GREEN "==============================================\
        =============\n" RESET);
	ft_printf(GREEN "                   🎉 CONGRATULATIONS! 🎉      \
        \n" RESET);
	ft_printf(GREEN "-----------------------------------------------\
        ------------\n" RESET);
	ft_printf(GREEN " You've successfully completed the game! 🏆    \
        \n" RESET);
	ft_printf(GREEN " Thanks for playing and being an awesome hero. \
        👑\n" RESET);
	ft_printf(GREEN " Remember: the real treasure was the journey al\
        l along! 💎 \n" RESET);
	ft_printf(GREEN "===============================================\
        ============\n" RESET);
	ft_printf(GREEN "\n");
}
