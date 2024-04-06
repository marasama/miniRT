/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:31:35 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/05 20:30:35 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	calc_cy_roots(t_cylinder *cy, t_ray *ray, double *roots, bool *hit)
{
	t_v3	u;
	t_v3	v;
	float	a;
	float	b;
	float	c;

	v = scale_v3(cy->normal, dot_v3(ray->direction, cy->normal));
	v = subtract_v3(ray->direction, v);
	u = scale_v3(cy->normal, (dot_v3(subtract_v3(ray->origin, cy->cordnts), cy->normal)));
	u = subtract_v3(subtract_v3(ray->origin, cy->cordnts), u);
	a = sqrt(dot_v3(v, v));
	b = dot_v3(v, u);
	c = sqrt(dot_v3(u, u)) - pow(cy->diameter / 2, 2);
	roots[0] = (-b - sqrt(pow(b, 2) - a * c)) / a;
	roots[1] = (-b + sqrt(pow(b, 2) - a * c)) / a;
}

void	change_cylinder_hit(t_cylinder *cy, t_ray *ray, double *roots, bool *a, bool *hit)
{
	t_v3	base_ray;
	double	dist[2];
	int				i;
	double	y;
	double t;

	i = -1;
	base_ray = subtract_v3(cy->cordnts, ray->origin);
	while (++i < 2)
		dist[i] = dot_v3(cy->normal, subtract_v3(scale_v3(ray->direction, roots[i]), base_ray));
	i = -1;
	while (++i < 2)
		hit[i] = (dist[i] >= 0 && dist[i] <= cy->height && roots[i] > EPSILON);
	i = -1;
	if (hit[0] && hit[1])
	{
		y = roots[0] < roots[1] ? dist[0] : dist[1];
		t = min(roots[0], roots[1]);
	}
	else
	{
		y = hit[0] ? dist[0] : dist[1];
		t = hit[0] ? roots[0] : roots[1];
	}
	
		if ((hit[0] || hit[1]) && ray->hit.hit_len > t && t > EPSILON)
		{
			ray->hit.hit_len = t;
		ray->hit.hit_point = add_v3(ray->origin, scale_v3(ray->direction, ray->hit.hit_len));
		ray->hit.normal = normalize(subtract_v3(ray->hit.hit_point,
					add_v3(scale_v3(cy->normal, y), cy->cordnts)));
		if (hit[1] & !hit[0])
			ray->hit.normal = scale_v3(ray->hit.normal, -1);
		ray->hit.color = cy->color;
		}
}

void	cylinder_intersect(t_list *cy, t_ray *ray, bool *a)
{
	t_cylinder	*tmp;
	t_list		*cylinders;
	double		roots[2];
	bool			hit[2];

	cylinders = cy;
	{
		tmp = cylinders->content;
		calc_cy_roots(tmp, ray, roots, hit);
		change_cylinder_hit(tmp, ray, roots, a, hit);
		cylinders = cylinders->next;
	}
}