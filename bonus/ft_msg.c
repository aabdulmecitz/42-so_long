/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:55 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:08:57 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_msg(char *msg, t_game *game)
{
	if (game)
	{
		if (game->map_alloc)
			ft_free_map(game);
		ft_destroy_window(game);
		free(game);
		game = NULL;
	}
	ft_printf(RED "ERROR:\n%s\n" RESET, msg);
	exit(EXIT_FAILURE);
}

void	ft_congrats_message(void)
{
	ft_printf(GREEN "\n");
	ft_printf(GREEN "==========================================\
=================\n" RESET);
	ft_printf(GREEN "                   🎉 CONGRATULATIONS! 🎉 \
                \n" RESET);
	ft_printf(GREEN "------------------------------------------\
-----------------\n" RESET);
	ft_printf(GREEN " You've successfully completed the game! \
🏆               \n" RESET);
	ft_printf(GREEN " Thanks for playing and being an awesome h\
ero. 👑          \n" RESET);
	ft_printf(GREEN " Remember: the real treasure was the journ\
ey all along! 💎 \n" RESET);
	ft_printf(GREEN "==========================================\
=================\n" RESET);
	ft_printf(GREEN "\n");
}

void	ft_failed_msg(void)
{
	ft_printf(RED "\n");
	ft_printf(RED "==============================================\
=============\n" RESET);
	ft_printf(RED "                     OH NOO!                  \
 \n" RESET);
	ft_printf(RED "----------------------------------------------\
-------------\n" RESET);
	ft_printf(RED " You've failed completed the game! \n" RESET);
	ft_printf(RED " Thanks for playing. You should try again. \n" RESET);
	ft_printf(RED " Remember: have enjoy!            \n" RESET);
	ft_printf(RED "==============================================\
=============\n" RESET);
	ft_printf(RED "\n");
}
