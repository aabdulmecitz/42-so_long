/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:55 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 14:58:39 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *msg, t_ctx *ctx)
{
	if (ctx)
	{
		if (ctx->map_alloc)
			free_map(ctx);
		win_destroy(ctx);
		free(ctx);
		ctx = NULL;
	}
	ft_printf(RED "ERROR:\n%s\n" RESET, msg);
	exit(EXIT_FAILURE);
}

void	congrats_msg(void)
{
	ft_printf(GREEN "\n");
	ft_printf(GREEN "==========================================\
=================\n" RESET);
	ft_printf(GREEN "                   🎉 CONGRATULATIONS! 🎉 \
                \n" RESET);
	ft_printf(GREEN "------------------------------------------\
-----------------\n" RESET);
	ft_printf(GREEN " You've successmap_matrisy completed the game! \
🏆               \n" RESET);
	ft_printf(GREEN " Thanks for playing and being an awesome h\
ero. 👑          \n" RESET);
	ft_printf(GREEN " Remember: the real treasure was the journ\
ey all along! 💎 \n" RESET);
	ft_printf(GREEN "==========================================\
=================\n" RESET);
	ft_printf(GREEN "\n");
}

void	failed_msg(void)
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
