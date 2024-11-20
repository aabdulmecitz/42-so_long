/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:17:46 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/19 22:55:37 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// int close_window(void *param)
// {
//     (void)param;
//     exit(0);
//     return (0);
// }

// char **ber_to_map_arr(t_data data, int fd)
// {
//     int i;
//     int k;
//     char **map;
//     i = 0;
//     k = 1;
//     while (k > 0)
//     {
//         map[i] = get_next_line(fd);
//         k = ft_strlen(map[i]);
//         i++;
//     }
//     return (map);
// }

// int main(int argc, char **argv)
// {
//     void *mlx;
//     void *win;
//     void *image;
//     void *player;
    
    
    
//     int h = 64;
//     int w = 64;
    
//     mlx = mlx_init();
//     if (!mlx) {
//         printf("MiniLibX başlatılamadı!\n");
//         return 1;
//     }

//     win = mlx_new_window(mlx, 1920, 1080, "Midgard");
//     if (!win) {
//         printf("Pencere oluşturulamadi!\n");
//         return 1;
//     }

//     mlx_mouse_show(mlx, win);
//     mlx_hook(win, 17, 0, close_window, NULL);

//     image = mlx_xpm_file_to_image(mlx, ".//vikings.xpm", &w, &h);
//     void *image2 = mlx_xpm_file_to_image(mlx, ".//vikings.xpm", &w + 32 , &h + 32);
    
//     if (!image) {
//         printf("XPM dosyasi yüklenemedi!\n");
//         return 1;
//     }    
//     player = mlx_xpm_file_to_image(mlx, "./textures/player.xpm", &w, &h);
//     if (!player) {
//         printf("XPM dosyasi yüklenemedi!\n");
//         return 1;
//     }
   
//     mlx_put_image_to_window(mlx, win, image, 0, 0);
//     mlx_put_image_to_window(mlx, win, image2, 32, 0);
//     /* mlx_put_image_to_window(mlx, win, image, 32, 32);
//     mlx_put_image_to_window(mlx, win, image, 32, 64);
//     mlx_put_image_to_window(mlx, win, image, 64, 64);
//     mlx_put_image_to_window(mlx, win, image, 64, 128);
//     mlx_put_image_to_window(mlx, win, image, 64, 0);
//     mlx_put_image_to_window(mlx, win, image, 96, 0);
//     mlx_put_image_to_window(mlx, win, image, 128, 0); */
    
//     mlx_put_image_to_window(mlx, win, player, 64, 32);

//     mlx_loop(mlx);
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     ===========================================================
    
//     void *mlx;
//     void *win;
//     void *image;
//     void *player;
    
//     int h = 64;
//     int w = 64;
    
//     mlx = mlx_init();
//     if (!mlx) {
//         printf("MiniLibX başlatılamadı!\n");
//         return 1;
//     }

//     win = mlx_new_window(mlx, 1920, 1080, "Midgard");
//     if (!win) {
//         printf("Pencere oluşturulamadi!\n");
//         return 1;
//     }

//     mlx_mouse_show(mlx, win);
//     mlx_hook(win, 17, 0, close_window, NULL);

//     image = mlx_xpm_file_to_image(mlx, ".//textures/techwall.xpm", &w, &h);
//     void *image2 = mlx_xpm_file_to_image(mlx, ".//textures/player.xpm", &w + 32 , &h + 32);
    
//     if (!image) {
//         printf("XPM dosyasi yüklenemedi!\n");
//         return 1;
//     }    
//     player = mlx_xpm_file_to_image(mlx, "./textures/player.xpm", &w, &h);
//     if (!player) {
//         printf("XPM dosyasi yüklenemedi!\n");
//         return 1;
//     }
   
//     mlx_put_image_to_window(mlx, win, image, 0, 0);
//     mlx_put_image_to_window(mlx, win, image2, 32, 0);
//     mlx_put_image_to_window(mlx, win, image, 32, 32);
//     mlx_put_image_to_window(mlx, win, image, 32, 64);
//     mlx_put_image_to_window(mlx, win, image, 64, 64);
//     mlx_put_image_to_window(mlx, win, image, 64, 128);
//     mlx_put_image_to_window(mlx, win, image, 64, 0);
//     mlx_put_image_to_window(mlx, win, image, 96, 0);
//     mlx_put_image_to_window(mlx, win, image, 128, 0);
    
//     mlx_put_image_to_window(mlx, win, player, 64, 32);

//     mlx_loop(mlx);
//     ===========================================================
    
//     return 0;
//}

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>

#define IMG_WIDTH 32
#define ANIM_SPEED 100000 // 0.1 saniye

typedef struct s_game {
    void *mlx_ptr;
    void *win_ptr;
} t_game;

typedef struct s_sprite {
    void *sprite_image;
    int sprite_columns;
} t_sprite;

int animate_sprite(t_game *game, t_sprite *sprite, int frame)
{
    int x;
    int y;

    x = (frame % sprite->sprite_columns) * IMG_WIDTH;
    y = 0;

    mlx_clear_window(game->mlx_ptr, game->win_ptr);
    if (sprite->sprite_image)
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->sprite_image, 0, 0);
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->sprite_image, x, y);
    }
    else
    {
        printf("Sprite image not loaded\n");
    }
    mlx_do_sync(game->mlx_ptr);
    usleep(ANIM_SPEED);
    return (0);
}

int make_animation(t_game *game, t_sprite *sprite)
{
    int frame;

    frame = 0;
    while (1)
    {
        animate_sprite(game, sprite, frame);
        frame = (frame + 1) % sprite->sprite_columns;
    }
    return (0);
}

void init_sprite(t_sprite *sprite, void *image, int columns)
{
    sprite->sprite_columns = columns;
    sprite->sprite_image = image;
}

int main()
{
    t_game game;
    t_sprite sprite;
    int img_width;
    int img_height;

    game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, 800, 600, "Sprite Animation");

    sprite.sprite_image = mlx_xpm_file_to_image(game.mlx_ptr, "sprite.xpm", &img_width, &img_height);
    if (!sprite.sprite_image)
    {
        printf("Error loading sprite image\n");
        return (1);
    }
    init_sprite(&sprite, sprite.sprite_image, img_width / IMG_WIDTH);

    make_animation(&game, &sprite);

    return (0);
}
