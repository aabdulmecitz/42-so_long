/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:00:21 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/10/24 21:18:49 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main()
{
    void *mlx;
    void *win;
    void *player;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 750, "My beautiful window");

    mlx_new_image("Viking(Ice Age)-Sheet.png", 64, 64);
   // mlx_put_image_to_window(mlx, win, player, 64, 64);
    mlx_mouse_show(mlx, win);
    mlx_hook(win, 17, 0, close_window, NULL);

    
    // int j = 0;
    // int i = 0;
    // while (j++ < 40)
    //     while (i++ < 500)
    //         mlx_pixel_put(mlx, win, i, i, 0xFFFFFF);
    // mlx_string_put(mlx, win, 150, 100, 0xFFFFFF, "Hi from aabdulmecitz :)");
    mlx_loop(mlx);
    return 0;
}
