/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:10:17 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/31 18:07:24 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg, t_ctx *ctx)
{
	if (ctx)
	{
		if (ctx->map_alloc && ctx->map.map_matris)
			free_map(ctx);
		if (ctx->mlx_ptr)
		{
			if (ctx->wall.xpm_ptr)
				mlx_destroy_image(ctx->mlx_ptr, ctx->wall.xpm_ptr);
			if (ctx->win_ptr)
				mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
			mlx_destroy_display(ctx->mlx_ptr);
			free(ctx->mlx_ptr);
		}
		free(ctx);
	}
	ft_printf(RED "ERROR:\n%s\n" RESET, msg);
	exit(EXIT_FAILURE);
}

void	error_cover(char *msg, t_ctx *ctx)
{
	if (ctx->map_alloc)
		free_map(ctx);
	if (ctx->wall.xpm_ptr)
		free(ctx->wall.xpm_ptr);
	free(ctx);
	ctx = NULL;
	ft_printf(RED "ERROR:\n%s\n" RESET, msg);
	exit(EXIT_FAILURE);
}

void	congrats_msg(void)
{
	ft_printf(GREEN "\n");
	ft_printf(GREEN "==============================================\n" RESET);
	ft_printf(GREEN "           🎉 CONGRATULATIONS! 🎉\n" RESET);
	ft_printf(GREEN "----------------------------------------------\n" RESET);
	ft_printf(GREEN " You finished the game! Well done! 🏆\n" RESET);
	ft_printf(GREEN " Thank you for playing so_long. 👾\n" RESET);
	ft_printf(GREEN " Hope you enjoyed the adventure!\n" RESET);
	ft_printf(GREEN "==============================================\n" RESET);
	ft_printf(GREEN "\n");
}
