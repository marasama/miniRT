/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:31:35 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/04 02:46:33 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	calc_cy_roots(t_cylinder *cy, t_ray *ray, double *roots)
{
	t_v3	u;
	t_v3	v;
	float	a;
	float	b;
	float	c;

	v = scale_v3(cy->normal, dot_v3(ray->direction, cy->normal));
	v = subtract_v3(ray->direction, v);
	u = scale_v3(cy->normal, dot_v3(subtract_v3(ray->origin, cy->cordnts), cy->normal));
	u = subtract_v3(subtract_v3(ray->origin, cy->cordnts), u);
	a = sqrt(dot_v3(v, v));
	b = dot_v3(v, u);
	c = sqrt(dot_v3(u, u)) - pow(cy->diameter, 2);
	roots[0] = (-b - sqrt(pow(b, 2) - a * c)) / a;
	roots[1] = (-b + sqrt(pow(b, 2) - a * c)) / a;
}

void	change_cylinder_hit(t_cylinder *cy, t_ray *ray, double *roots)
{
	t_v3	base_ray;
	double	dist[2];

	base_ray = subtract_v3(cy->cordnts, ray->origin);
}

void	cylinder_intersect(t_list *cy, t_ray *ray, bool *a)
{
	t_cylinder	*tmp;
	t_list		*cylinders;
	double		roots[2];

	cylinders = cy;
	{
		tmp = cylinders->content;
		calc_cy_roots(tmp, ray, roots);
		change_cylinder_hit(tmp, ray, roots);
		cylinders = cylinders->next;
	}
}