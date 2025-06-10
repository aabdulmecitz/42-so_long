/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ctx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:42 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/24 21:47:13 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_long_init(t_ctx *ctx);
void	ft_init_mlx(t_ctx *ctx);
void	ft_init_sprites(t_ctx *ctx);

void	so_long_init(t_ctx *ctx)
{
	ctx->ctx_num = 0;
	ctx->map.coins = 0;
	ctx->map.exit = 0;
	ctx->map.players = 0;
	ctx->movements = 0;
	ctx->enemy_k_num = 0;
	ctx->enemy_x_num = 0;
	conf_null(ctx);
	ctx->map.columns = ft_strlen(ctx->map.map_matris[0]) - 1;
	while (ctx->map.map_matris[ctx->map.rows])
		ctx->map.rows++;
	ctx->player_dir = FRONT;
	ft_init_mlx(ctx);
	ft_init_sprites(ctx);
	ft_printf(GREEN "ctx initialization successful!\n" RESET);
}

void	ft_init_mlx(t_ctx *ctx)
{
	ctx->mlx_ptr = mlx_init();
	if (!ctx->mlx_ptr)
		error("Couldn't find mlx pointer. Try it using a VNC.", ctx);
	ctx->win_ptr = mlx_new_window(ctx->mlx_ptr,
			(ctx->map.columns + 1) * IMG_WIDTH,
			(ctx->map.rows + 2) * IMG_HEIGHT, "so_long");
	if (!ctx->win_ptr)
	{
		free(ctx->mlx_ptr);
		error("Couldn't create the Window.", ctx);
	}
}

void	load_sprite(t_img *sprite, void *mlx, char *path, t_ctx *ctx)
{
	if (!sprite)
		error(" ", ctx);
	sprite->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite->x, &sprite->y);
	ft_printf(CYAN "Loading sprite from path: %s\n" RESET, path);
	if (!sprite->xpm_ptr)
	{
		ft_printf(RED "Failed to load sprite: %s\n" RESET, path);
		error("Couldn't find a sprite. Does it exist?", ctx);
	}
}

void	ft_init_sprites(t_ctx *ctx)
{

	void	*mlx;

	mlx = ctx->mlx_ptr;
	load_sprite(ctx->wall, mlx, WALL_XPM1, ctx);
	load_sprite(ctx->floor, mlx, FLOOR_XPM, ctx);
	load_sprite(ctx->coins, mlx, COINS_XPM1, ctx);
	load_sprite(ctx->player_front, mlx, PLAYER_FRONT_XPM1, ctx);
	load_sprite(ctx->player_left, mlx, PLAYER_LEFT_XPM2, ctx);
	load_sprite(ctx->player_right, mlx, PLAYER_RIGHT_XPM3, ctx);
	load_sprite(ctx->player_back, mlx, PLAYER_BACK_XPM4, ctx);
	load_sprite(ctx->open_exit, mlx, OPEN_EXIT_XPM, ctx);
	load_sprite(ctx->exit_closed, mlx, EXIT_CLOSED_XPM, ctx);
	load_sprite(ctx->enemy_x_l, mlx, WANDER_ENEMY_L_XPM1, ctx);
	load_sprite(ctx->enemy_x_r, mlx, WANDER_ENEMY_R_XPM1, ctx);
	load_sprite(ctx->enemy_k, mlx, TOXIC_XPM1, ctx);
}
