/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:42:47 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/21 01:48:34 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_double(void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
	if (ptr1)
		free(ptr1);
	if (ptr1)
		free(ptr2);
	if (ptr1)
		free(ptr3);
	if (ptr1)
		free(ptr4);
}

void	free_image_list(t_image *head, void *mlx_ptr)
{
	t_image	*current;
	t_image	*temp;

	current = head;
	while (current)
	{
		temp = current->next;
		if (current->xpm_ptr && mlx_ptr)
			mlx_destroy_image(mlx_ptr, current->xpm_ptr);
		free(current);
		current = temp;
	}
}
