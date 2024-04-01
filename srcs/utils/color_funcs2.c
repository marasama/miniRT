/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 05:30:51 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/01 10:12:30 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

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

float	light_intensity(t_light light, t_hit hit)
{
	t_v3	light_direction;
	float	light_ratio;
	float	distance;
	float	intensity;

	light_direction = subtract_v3(light.cordnts, hit.hit_point);
	distance = dot_v3(light_direction, light_direction);
	light_ratio = dot_v3(normalize(light_direction), hit.normal);
	if (light_ratio <= 0)
		return (0);
	intensity = (light.brightness * light_ratio * REFLECT)
		/ (4.0 * PI * distance);
	return (intensity);
}

int	color_comp(t_light light, t_hit hit)
{
	int		object_color;
	int		color;

	color = 0;
	object_color = hit.color;
	color = add_color(color, scale_color(object_color,
				light_intensity(light, hit)));
	color = color_product(color, light.color);
	return (color);
}

bool	check_shadow(t_all **all, t_light *light, t_hit hit)
{
	t_ray	shadow;

	shadow.origin = add_v3(hit.hit_point, scale_v3(hit.normal, 0.0001));
	shadow.direction = normalize(subtract_v3(light->cordnts, shadow.origin));
	shadow.hit.object = hit.object;
	shadow.hit.hit_len = INFINITY;
	return (check_intersection(all, &shadow));
}

int	re_color(t_all **all, t_ray *ray)
{
	int		ambient;
	t_light	*light;
	int		color;
	bool	check;

	light = (*all)->world->light;
	ambient = scale_color((*all)->world->ambient->color,
			(*all)->world->ambient->l_ratio);
	color = color_product(ray->hit.color, ambient);
	check = check_shadow(all, light, ray->hit);
	color = add_color(color, check * color_comp(*light, ray->hit));
	return (color);
}
