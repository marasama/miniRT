/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:31:35 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/26 21:33:41 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <math.h>

void	hit_cylinder_cap(t_cylinder *cy, t_ray *ray, double height, bool *a)
{
	t_v3		circle_center;
	t_v3		intersect;
	double		r;
	double		root;
	double		distance;

	r = cy->diameter / 2;
	circle_center = add_v3(cy->cordnts, scale_v3(cy->normal, height));
	root = dot_v3(subtract_v3(circle_center, ray->origin), cy->normal) \
				/ dot_v3(ray->direction, cy->normal);
	intersect = add_v3(ray->origin, scale_v3(ray->direction, root));
	distance = len_v3(subtract_v3(intersect, circle_center));
	if (fabs(distance) > r)
		return ;
	if (root < EPSILON || root > 1000 || root > ray->hit.hit_len)
		return ;
	ray->hit.hit_len = root;
	ray->hit.hit_point = add_v3(ray->origin, scale_v3(ray->direction, root));
	ray->hit.color = cy->color;
	*a = true;
	if (height > 0)
		ray->hit.normal = cy->normal;
	else
		ray->hit.normal = scale_v3(cy->normal, -1);
}

bool	cy_boundary(t_cylinder *cy, t_ray *ray, double root)
{
	double	max_height;
	double	hit_height;
	t_v3	tmp;

	tmp = add_v3(ray->origin, scale_v3(ray->direction, root));
	hit_height = dot_v3(subtract_v3(tmp, cy->cordnts), cy->normal);
	max_height = cy->height / 2;
	if (fabs(hit_height) > max_height)
		return (false);
	return (true);
}

bool	calc_cy_roots(t_cylinder *cy, t_ray *ray, double *roots)
{
	t_v3	delta;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	delta = subtract_v3(ray->origin, cy->cordnts);
	a = pow(len_v3(cross_v3(ray->direction, cy->normal)), 2);
	half_b = dot_v3(cross_v3(ray->direction, cy->normal), \
			cross_v3(delta, cy->normal));
	c = pow(len_v3(cross_v3(delta, cy->normal)), 2) - pow(cy->diameter / 2, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (false);
	roots[0] = (-half_b - sqrt(discriminant)) / a;
	roots[1] = (-half_b + sqrt(discriminant)) / a;
	if (roots[0] > 1000 || roots[0] < EPSILON)
	{
		roots[0] = roots[1];
		if (roots[0] > 1000 || roots[0] < EPSILON)
			return (false);
	}
	return (cy_boundary(cy, ray, roots[0]));
}

void	hit_cylinder_side(t_cylinder *cy, t_ray *ray, double *roots, bool *a)
{
	double	hit_height;
	t_v3	tmp;
	int		i;

	i = 0;
	if (!calc_cy_roots(cy, ray, roots))
		return ;
	tmp = add_v3(ray->origin, scale_v3(ray->direction, roots[0]));
	hit_height = dot_v3(subtract_v3(tmp, cy->cordnts), cy->normal);
	while (i < 2)
	{
		if (roots[i] < ray->hit.hit_len && roots[i] > EPSILON)
		{
			ray->hit.hit_len = roots[i];
			ray->hit.hit_point = add_v3(ray->origin, \
					scale_v3(ray->direction, roots[i]));
			ray->hit.normal = normalize(subtract_v3(ray->hit.hit_point, \
					add_v3(cy->cordnts, scale_v3(cy->normal, hit_height))));
			ray->hit.color = cy->color;
			*a = true;
		}
		i++;
	}
}

void	cylinder_intersect(t_list *cy, t_ray *ray, bool *a)
{
	t_cylinder	*tmp;
	t_list		*cylinders;
	double		roots[2];

	cylinders = cy;
	while (cylinders != NULL)
	{
		tmp = cylinders->content;
		hit_cylinder_cap(tmp, ray, (tmp->height / 2), a);
		hit_cylinder_cap(tmp, ray, -(tmp->height / 2), a);
		hit_cylinder_side(tmp, ray, roots, a);
		cylinders = cylinders->next;
	}
}
