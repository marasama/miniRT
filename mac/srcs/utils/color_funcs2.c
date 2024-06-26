/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 05:30:51 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/26 21:33:03 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <math.h>

int	color_product(int color_a, int color_b)
{
	int		r;
	int		g;
	int		b;

	r = (((float)(color_a >> 16) / 255)
			* ((float)(color_b >> 16) / 255)) * 255;
	g = (((float)((color_a >> 8) & 255) / 255)
			* ((float)((color_b >> 8) & 255) / 255)) * 255;
	b = (((float)(color_a & 255) / 255)
			* ((float)(color_b & 255) / 255)) * 255;
	return ((r << 16) | (g << 8) | b);
}

double	light_intensity(t_light light, t_hit hit)
{
	t_v3	light_direction;
	double	light_ratio;
	double	distance;
	double	intensity;

	light_direction = subtract_v3(light.cordnts, hit.hit_point);
	distance = dot_v3(light_direction, light_direction);
	light_ratio = dot_v3(normalize(light_direction), hit.normal);
	if (light_ratio <= 0)
		return (0);
	intensity = light.brightness * light_ratio;
	return (intensity);
}

int	color_comp(t_light light, t_hit hit)
{
	int		color;

	color = 0;
	color = add_color(color, scale_color(hit.color,
				light_intensity(light, hit)));
	color = color_product(color, light.color);
	return (color);
}

int	check_shadow(t_all **all, t_light *light, t_hit hit)
{
	t_ray	shadow;
	t_v3	light_direction;
	double	distance;

	light_direction = subtract_v3(light->cordnts, hit.hit_point);
	distance = sqrt(dot_v3(light_direction, light_direction));
	shadow.origin = add_v3(hit.hit_point, scale_v3(hit.normal, EPSILON));
	shadow.direction = normalize(light_direction);
	shadow.hit.hit_len = distance;
	if (check_intersection(all, &shadow))
	{
		if (shadow.hit.hit_len > EPSILON)
			return (1);
	}
	return (0);
}

int	re_color(t_all **all, t_ray *ray)
{
	int		ambient;
	t_light	*light;
	int		color;

	color = 0;
	light = (*all)->world->light;
	if ((*all)->world->ambient != NULL)
	{
		ambient = scale_color((*all)->world->ambient->color, \
				(*all)->world->ambient->l_ratio);
		color = color_product(ray->hit.color, ambient);
	}
	else
		color = ray->hit.color;
	if (light == NULL)
		return (color);
	if (check_shadow(all, light, ray->hit))
		return (color);
	color = add_color(color, color_comp(*light, ray->hit));
	return (color);
}
