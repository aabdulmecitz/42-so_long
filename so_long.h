/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:16:28 by aozkaya           #+#    #+#             */
/*   Updated: 2024/11/12 16:05:10 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#  define SQW = 64
#  define SQH = 64

#  define PWALK = 6
#  define PSTAND = 6
#  define PDEATH = 6
#  define PCOLLECT = 6

#  define PGREET = 6

#  define EWALK = 6
#  define EATTACk = 6

#  define COINANIM = 6

typedef struct s_animation {
    char **frames;
    int num_frames;
    int current_frame;
    int speed;
} t_animation;




#endif