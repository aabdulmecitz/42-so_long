/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:35:52 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/21 01:16:42 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image_creator(t_game *game, t_image *new_image,
			const char *current_path);

void	init_animation(t_game *game, t_image **image, ...)
{
	va_list		args;
	t_image		*new_image;
	const char	*current_path;
	t_image		*temp;

	va_start(args, image);
	current_path = va_arg(args, const char *);
	while (current_path != NULL)
	{
		new_image = malloc(sizeof(t_image));
		image_creator(game, new_image, current_path);
		if (*image != NULL)
		{
			temp = *image;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_image;
		}
		else
			*image = new_image;
		current_path = va_arg(args, const char *);
	}
	va_end(args);
}

void	init_all_of_animations(t_game *game)
{
	init_animation(game, &game->coins, "assets/sprites/coin/coin2.xpm", \
"assets/sprites/coin/coin3.xpm", "assets/sprites/coin/coin4.xpm", NULL);
}

void	run_animation(t_game *game, t_image *image_list)
{
	static time_t	last_time;
	static t_image	*current_image;
	time_t			current_time;

	last_time = 0;
	current_image = NULL;
	current_time = time(NULL);
	if (difftime(current_time, last_time) * 1000 >= DELAY)
	{
		if (current_image == NULL)
			current_image = image_list;
		if (current_image && current_image->xpm_ptr)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					current_image->xpm_ptr, current_image->x, current_image->y);
		}
		current_image = current_image->next;
		if (current_image == NULL)
			current_image = image_list;
		last_time = current_time;
		printf("coin ptr: %p\n", current_image->xpm_ptr);
	}
}

void	image_creator(t_game *game, t_image *new_image,
		const char *current_path)
{
	if (!new_image)
		ft_error_msg("Memory allocation failed for image node.", game);
	ft_load_sprite(new_image, game->mlx_ptr, (char *)current_path, game);
	new_image->next = NULL;
}
