/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:35:52 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/17 03:26:21 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    init_animation(t_game *game, t_image **image, ...)
{
    va_list args;
    t_image *new_image;
    const char *current_path;

    va_start(args, image);
    current_path = va_arg(args, const char *);
    while (current_path != NULL)
    {
        new_image = malloc(sizeof(t_image));
        if (!new_image)
            ft_error_msg("Memory allocation failed for image node.", game);
        ft_load_sprite(new_image, game->mlx_ptr, (char *)current_path, game);
        new_image->next = NULL;
        if (*image != NULL) // Bağlı liste boş değilse sona ekle
        {
            t_image *temp = *image;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new_image;
        }
        else // Bağlı liste boşsa ilk düğümü ekle
            *image = new_image;
        current_path = va_arg(args, const char *);
    }
    va_end(args);
}

void    init_all_of_animations(t_game *game)
{
    init_animation(game, &game->coins, 
        "assets/sprites/coin/coin2.xpm",
        "assets/sprites/coin/coin3.xpm",
        "assets/sprites/coin/coin4.xpm", NULL);
}



void    run_animation(t_game *game, t_image *image_list)
{
    static time_t last_time = 0;
    static t_image *current_image = NULL;
    time_t current_time;

    current_time = time(NULL);

    if (difftime(current_time, last_time) * 1000 >= delay)
    {
        if (current_image == NULL)
            current_image = image_list;
        if (current_image && current_image->xpm_ptr)
        {
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
                current_image->xpm_ptr, current_image->x, current_image->y);
        }
        current_image = current_image->next;
        if (current_image == NULL)
            current_image = image_list;
        last_time = current_time;
        printf("coin ptr: %p\n", current_image->xpm_ptr);
    }

}


