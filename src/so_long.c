/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:10:28 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/31 19:02:21 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_ctx(t_ctx *ctx)
{
	free_all_mem(ctx);
	ft_printf(GREEN "game closed success full.\n" RESET);
	exit(0);
	return (0);
}

void	print_map_matris(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i)
	{
		i++;
		ft_printf("%s|size: %d\n", ctx->map.map_matris[i],
			(int)ft_strlen(ctx->map.map_matris[i]));
	}
}

int	main(int argc, const char *argv[])
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
	{
		ft_printf(RED "ERROR:\nMemory allocation failed for ctx\n" RESET);
		exit(EXIT_FAILURE);
	}
	ft_memset(ctx, 0, sizeof(t_ctx));
	ctx->map_alloc = 0;
	ctx->mlx_ptr = NULL;
	ctx->win_ptr = NULL;
	check_cmd_args(argc, argv, ctx);
	map_initializer(ctx, (char *)argv[1]);
	so_long_init(ctx);
	map_checker(ctx);
	print_map_matris(ctx);
	ft_printf("player's x = %d, player's y = %d\n", ctx->map.player.x, \
		ctx->map.player.y);
	mlx_loop_hook(ctx->mlx_ptr, render_a_frame, ctx);
	handler(ctx);
	mlx_loop(ctx->mlx_ptr);
	return (0);
}
