/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:51:08 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/25 17:42:59 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	set_color(t_all **all, int x, int y, t_color color)
{
	int	index;

	index = ((*all)->mlx->size_line * y) + (x * ((*all)->mlx->bpp / 8));
	(*all)->mlx->pixels[index] = color.blue;
	(*all)->mlx->pixels[index + 1] = color.green;
	(*all)->mlx->pixels[index + 2] = color.red;
	(*all)->mlx->pixels[index + 3] = 0;
}

int	color_to_int(t_color v3_color)
{
	int	color;

	color = 0;
	color = (color << 8) | v3_color.red;
	color = (color << 8) | v3_color.green;
	color = (color << 8) | v3_color.blue;
	return (color);
}

t_color	int_to_color(int color)
{
	t_color	result;

	result.blue = color & 0xFF;
	color >>= 8;
	result.green = color & 0xFF;
	color >>= 8;
	result.red = color & 0xFF;
	return (result);
}

int	add_color(int color_a, int color_b)
{
	int		r;
	int		g;
	int		b;

	r = clamp((color_a >> 16) + (color_b >> 16), 255, 0);
	g = clamp((color_a >> 8 & 255) + (color_b >> 8 & 255), 255, 0);
	b = clamp((color_a & 255) + (color_b & 255), 255, 0);
	return ((r << 16) | (g << 8) | b);
}

int	scale_color(int color, float c)
{
	int		r;
	int		g;
	int		b;

	r = clamp(c * (color >> 16), 255, 0);
	g = clamp(c * ((color >> 8) & 255), 255, 0);
	b = clamp(c * (color & 255), 255, 0);
	return ((r << 16) | (g << 8) | b);
}
