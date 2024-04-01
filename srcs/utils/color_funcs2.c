/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 05:30:51 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/01 05:45:55 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	color_product(int color_a, int color_b)
{
	int		r;
	int		g;
	int		b;

	r = (((float)(color_a >> 16) / 255) *
			((float)(color_b >> 16) / 255)) * 255;
	g = (((float)((color_a >> 8) & 255) / 255) *
			((float)((color_b >> 8) & 255) / 255)) * 255;
	b = (((float)(color_a & 255) / 255) *
			((float)(color_b & 255) / 255)) * 255;
	return ((r << 16) | (g << 8) | b);
}

float	light_intensity(t_light light, t_hit hit)
{
	t_v3	light_direction;
	float	light_ratio;
	float	distance;
	float	intensity;

	light_direction = subtract_v3(light.cordnts, hit.hitPoint);
	distance = dot_v3(light_direction, light_direction);
	light_ratio = dot_v3(normalize(light_direction), hit.normal);
	if (light_ratio <= 0)
		return (0);
	intensity = (light.brightness * light_ratio * REFLECT) / (4.0 * PI * distance);
	return (intensity);
}

int	color_comp(t_light light, t_hit hit)
{
	int		object_color;
	int		color;

	color = 0;
	object_color = hit.color;
	color = add_color(color, scale_color(object_color, light_intensity(light, hit)));
	color = color_product(color, colorToInt(light.color));
	return (color);
}