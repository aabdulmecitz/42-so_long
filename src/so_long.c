/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:00:21 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/19 22:55:46 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void init_sprite(t_sprite *sprite, void *image, int columns)
{
    sprite->sprite_image = image;
    sprite->sprite_columns = columns;
}

int animate_sprite(t_game *game, t_sprite *sprite, int frame)
{
    int x;

    x = (frame % sprite->sprite_columns) * IMG_WIDTH;
    mlx_clear_window(game->mlx_ptr, game->win_ptr);
    if (sprite->sprite_image)
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->sprite_image, x, 0);
    }
    else
    {
        printf("Sprite image not loaded!\n");
        return (1);
    }
    usleep(ANIM_SPEED);
    return (0);
}

int make_animation(t_game *game, t_sprite *sprite)
{
    int frame = 0;

    while (1)
    {
        if (animate_sprite(game, sprite, frame))
            break;
        frame = (frame + 1) % sprite->sprite_columns;
    }
    return (0);
}

int main(int argc, char const *argv[]) {
    t_game *game;
    t_sprite *player;
    int img_width, img_height;

    game = (t_game*)malloc(sizeof(t_game));
    if (!game) {
        printf("Error: Failed to allocate memory for game\n");
        return 1;
    }

    player = (t_sprite*)malloc(sizeof(t_sprite));
    if (!player) {
        printf("Error: Failed to allocate memory for sprite\n");
        free(game);
        return 1;
    }

    // Initialize MLX
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr) {
        printf("Error: Failed to initialize MLX\n");
        free(game);
        free(player);
        return 1;
    }

    game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_W, WIN_H, "Valhalla");
    if (!game->win_ptr) {
        printf("Error: Failed to create window\n");
        free(game);
        free(player);
        return 1;
    }

    // Load Sprite Image
    player->sprite_image = mlx_xpm_file_to_image(game->mlx_ptr, "../textures/player.xpm", &img_width, &img_height);
    if (!player->sprite_image)
    {
        printf("Error loading sprite image\n");
        free(game);
        free(player);
        return (1);
    }

    // Initialize sprite with the correct image and columns
    init_sprite(player, player->sprite_image, img_width / IMG_WIDTH);

    make_animation(game, player);

    free(player);
    free(game);
    return 0;
}