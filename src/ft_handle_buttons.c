/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:51:50 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/26 04:40:38 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_destroy_window(int keycode, t_game *game)
{
    if (keycode == KEY_ESC || keycode == KEY_Q)
    {
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        ft_free_all_allocated_memory(game);
        exit(0);
    }
}

void ft_player_move(int keycode, t_game *game)
{
    int x = game->map.player.x;
    int y = game->map.player.y;

    if ((keycode == KEY_W || keycode == KEY_UP) && game->map.full[y - 1][x] != WALL)
    {
        if ()
        {
            
        }
        game->map.full[y][x] = FLOOR;
        game->map.player.y -= 1;
        game->map.full[y - 1][x] = PLAYER;
    }
    else if ((keycode == KEY_S || keycode == KEY_DOWN) && game->map.full[y + 1][x] != WALL)
    {
        
        game->map.full[y][x] = FLOOR;
        game->map.player.y += 1;
        game->map.full[y + 1][x] = PLAYER;
    }
    else if ((keycode == KEY_A || keycode == KEY_LEFT) && game->map.full[y][x - 1] != WALL)
    {
        game->map.full[y][x] = FLOOR;
        game->map.player.x -= 1;
        game->map.full[y][x - 1] = PLAYER;
        }
    else if ((keycode == KEY_D || keycode == KEY_RIGHT) && game->map.full[y][x + 1] != WALL)
    {
        game->map.full[y][x] = FLOOR;
        game->map.player.x += 1;
        game->map.full[y][x + 1] = PLAYER;
    }
}


int key_hook(int keycode, t_game *game)
{
    ft_player_move(keycode, game);
    ft_destroy_window(keycode, game);
    ft_print_map_full(game);

    printf("Oyuncunun yeni pozisyonu: (%d, %d)\n", game->map.player.x, game->map.player.y);
    return 0;
}

void ft_handle_buttons(t_game *game)
{
    mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_hook, game);
}




//int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

// KeyPress (Tuş Basma Olayı)

// Kod Numarası: 2

// Mask: 1L << 0 (KeyPressMask)

// Açıklama: Kullanıcı bir tuşa bastığında tetiklenir.

// KeyRelease (Tuş Bırakma Olayı)

// Kod Numarası: 3

// Mask: 1L << 1 (KeyReleaseMask)

// Açıklama: Kullanıcı bir tuşu bıraktığında tetiklenir.

// ButtonPress (Fare Düğmesine Basma Olayı)

// Kod Numarası: 4

// Mask: 1L << 2 (ButtonPressMask)

// Açıklama: Kullanıcı fare düğmesine bastığında tetiklenir.

// ButtonRelease (Fare Düğmesini Bırakma Olayı)

// Kod Numarası: 5

// Mask: 1L << 3 (ButtonReleaseMask)

// Açıklama: Kullanıcı fare düğmesini bıraktığında tetiklenir.

// MotionNotify (Fare Hareketi Olayı)

// Kod Numarası: 6

// Mask: 1L << 6 (PointerMotionMask)

// Açıklama: Kullanıcı fareyi hareket ettirdiğinde tetiklenir.

// Expose (Pencere Güncelleme Olayı)

// Kod Numarası: 12

// Mask: 1L << 15 (ExposureMask)

// Açıklama: Pencere güncellenmesi gerektiğinde (örneğin pencere yeniden boyutlandırıldığında veya gizlenip yeniden gösterildiğinde) tetiklenir.

// DestroyNotify (Pencere Kapanma Olayı)

// Kod Numarası: 17

// Mask: 0

// Açıklama: Pencere kapandığında tetiklenir.