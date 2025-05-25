/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:10:17 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 14:58:47 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg, t_ctx *ctx)
{
	if (ctx)
	{
		if (ctx->map_alloc)
			free_map(ctx);
		if (ctx->wall.xpm_ptr)
			free(ctx->wall.xpm_ptr);
		free(ctx);
		ctx = NULL;
	}
	ft_printf(RED "ERROR:\n%s\n" RESET, msg);
	exit(EXIT_FAILURE);
}

void	congrats_msg(void)
{
	ft_printf(GREEN "\n");
	ft_printf(GREEN "==============================================\
=============\n" RESET);
	ft_printf(GREEN "                   🎉 CONGRATULATIONS! 🎉 \n" RESET);
	ft_printf(GREEN "-----------------------------------------------\
------------\n" RESET);
	ft_printf(GREEN " You've successmap_matrisy completed the game! 🏆 \n" RESET);
	ft_printf(GREEN " Thanks for playing and being an awesome hero. \
👑\n" RESET);
	ft_printf(GREEN " Remember: the real treasure was the journey al\
l along! 💎 \n" RESET);
	ft_printf(GREEN "===============================================\
============\n" RESET);
	ft_printf(GREEN "\n");
}
