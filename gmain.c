/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:17:46 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/11/15 00:18:25 by aabdulmecit      ###   ########.fr       */
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

