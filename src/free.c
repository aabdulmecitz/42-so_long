/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:35 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:09:37 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
