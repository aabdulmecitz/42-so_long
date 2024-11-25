/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:51:50 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/25 23:36:16 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_close_the_window(t_game game);
void    ft_player_move(t_game *game);

// int ft_handle_button(t_game *game)
// {
// }
// void    ft_close_the_window(t_game game)
// {
    
// }

// void    ft_player_move(t_game *game)
// {
    
// }

int key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_W || keycode == KEY_UP)
        game->map.player.y -= 1;
    else if (keycode == KEY_S || keycode == KEY_DOWN)
        game->map.player.y += 1;
    else if (keycode == KEY_A || keycode == KEY_LEFT)
        game->map.player.x -= 1;
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
        game->map.player.x += 1;
    else if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        ft_free_all_allocated_memory(game);
        exit(0);
    }
    ft_print_map_full(game);

    printf("Oyuncunun yeni pozisyonu: (%d, %d)\n", game->map.player.x, game->map.player.y);
    // Ekranı yeniden çizme fonksiyonunu burada çağırabilirsiniz.
    // örneğin: ft_draw_map(game);
    return (0);
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