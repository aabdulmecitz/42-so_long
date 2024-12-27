/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:20 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:07:22 by aozkaya          ###   ########.fr       */
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
