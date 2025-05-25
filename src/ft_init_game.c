/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ctx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:59 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/24 21:47:13 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		so_long_init(t_ctx *ctx);
void		ft_init_vars(t_ctx *ctx);
void		ft_init_mlx(t_ctx *ctx);
void		ft_init_sprites(t_ctx *ctx);
t_img		*ft_new_sprite(void *mlx, char *path, t_ctx *ctx);

void	so_long_init(t_ctx *ctx)
{
	ft_init_vars(ctx);
	ft_init_mlx(ctx);
	ft_init_sprites(ctx);
	ft_printf(GREEN "ctx initialization successful!\n" RESET);
}

void	ft_init_vars(t_ctx *ctx)
{
	ctx->map.coins = 0;
	ctx->map.exit = 0;
	ctx->map.players = 0;
	ctx->movements = 0;
	ctx->map.columns = ft_strlen(ctx->map.map_matris[0]) - 1;
	while (ctx->map.map_matris[ctx->map.rows])
		ctx->map.rows++;
	ctx->player_dir = FRONT;
}

void	ft_init_mlx(t_ctx *ctx)
{
	ctx->mlx_ptr = mlx_init();
	if (!ctx->mlx_ptr)
		error("Couldn't find mlx pointer. Try it using a VNC.", ctx);
	ctx->win_ptr = mlx_new_window(ctx->mlx_ptr, \
		(ctx->map.columns + 1) * IMG_WIDTH, ctx->map.rows * IMG_HEIGHT, \
		"so_long");
	if (!ctx->win_ptr)
	{
		free(ctx->mlx_ptr);
		error("Couldn't create the Window.", ctx);
	}
}

static void	load_sprite(t_img *sprite, void *mlx, char *path, t_ctx *ctx)
{
	t_img	*temp;

	temp = malloc(sizeof(t_img));
	if (!temp)
		error("Memory allocation failed for sprite.", ctx);
	temp->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &temp->x, &temp->y);
	ft_printf(CYAN "Loading sprite from path: %s\n" RESET, path);
	if (!temp->xpm_ptr)
	{
		ft_printf(RED "Failed to load sprite: %s\n" RESET, path);
		free(temp);
		error("Couldn't find a sprite. Does it exist?", ctx);
	}
	*sprite = *temp;
	free(temp);
}

void	ft_init_sprites(t_ctx *ctx)
{
	void	*mlx;

	mlx = ctx->mlx_ptr;
	load_sprite(&ctx->wall, mlx, WALL_XPM, ctx);
	load_sprite(&ctx->floor, mlx, FLOOR_XPM, ctx);
	load_sprite(&ctx->coins, mlx, COINS_XPM, ctx);
	load_sprite(&ctx->player_front, mlx, PLAYER_FRONT_XPM, ctx);
	load_sprite(&ctx->player_left, mlx, PLAYER_LEFT_XPM, ctx);
	load_sprite(&ctx->player_right, mlx, PLAYER_RIGHT_XPM, ctx);
	load_sprite(&ctx->player_back, mlx, PLAYER_BACK_XPM, ctx);
	load_sprite(&ctx->open_exit, mlx, OPEN_EXIT_XPM, ctx);
	load_sprite(&ctx->exit_closed, mlx, EXIT_CLOSED_XPM, ctx);
}
