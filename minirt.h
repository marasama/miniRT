/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:18:04 by adurusoy          #+#    #+#             */
/*   Updated: 2024/01/08 16:25:51 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./minilibx/mlx.h"

# define WIDTH 600
# define HEIGHT 600

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	void			*image;
	unsigned char	*pixels;
	int				bpp;
	int				endian;
	int				size_line;
}	t_mlx;




#endif
