/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 03:26:18 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/31 07:24:26 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# ifdef __APPLE__
#  define CROSS 17
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
# else
#  define CROSS 17
#  define ESC 65307
#  define UP_ARROW 65362
#  define LEFT_ARROW 65361
#  define DOWN_ARROW 65364
#  define RIGHT_ARROW 65363
# endif

#endif