/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_pl_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:52:23 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/08 17:05:57 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <stdio.h>

void	calc_roots(t_sphere *sp, t_ray *ray, double *roots)
{
	t_v3	v2sp;
	double	dot_a;
	double	dot_b;
	double	dot_c;
	double	discr;

	v2sp = subtract_v3(ray->origin, sp->cordnts);
	dot_a = dot_v3(ray->direction, ray->direction);
	dot_b = dot_v3(v2sp, ray->direction) * 2.0f;
	dot_c = dot_v3(v2sp, v2sp) - (sp->diameter * sp->diameter / 4.0f);
	discr = dot_b * dot_b - (4 * dot_a * dot_c);
	if (discr < 0)
	{
		roots[0] = INFINITY;
		roots[1] = INFINITY;
	}
	else
	{
		roots[0] = ((-dot_b - sqrt(discr)) / (dot_a * 2));
		roots[1] = ((-dot_b + sqrt(discr)) / (dot_a * 2));
	}
}

void	change_sphere_hit(t_sphere *sp, t_ray *ray, double *roots, bool *a)
{
	int	i;

	i = 0;
	if (roots[0] > roots[1])
		i = 1;
	if (roots[i] < ray->hit.hit_len && roots[i] > EPSILON)
	{
		ray->hit.hit_len = roots[i];
		ray->hit.hit_point = add_v3(ray->origin,
				scale_v3(ray->direction, roots[i]));
		ray->hit.normal = normalize(subtract_v3(ray->hit.hit_point,
					sp->cordnts));
		ray->hit.color = sp->color;
		ray->hit.type = SPHERE;
		*a = true;
	}
}

void	sphere_intersect(t_all **all, t_ray *ray, bool *a)
{
	t_list		*sphere_list;
	t_sphere	*tmp;
	int			i;
	double		roots[2];

	i = 0;
	sphere_list = (*all)->world->spheres;
	while (sphere_list != NULL)
	{
		tmp = sphere_list->content;
		calc_roots(tmp, ray, roots);
		change_sphere_hit(tmp, ray, roots, a);
		sphere_list = sphere_list->next;
	}
}

void	change_plane_hit(t_plane *pl, t_ray *ray, double parallel, bool *a)
{
	double	hit;

	hit = dot_v3(subtract_v3(pl->cordnts, ray->origin), pl->normal)
		/ parallel;
	if (ray->hit.hit_len > hit && hit > EPSILON)
	{
		ray->hit.hit_len = hit;
		ray->hit.hit_point = add_v3(ray->origin, scale_v3(ray->direction, hit));
		ray->hit.hit_point = add_v3(ray->hit.hit_point, \
						scale_v3(pl->normal, EPSILON));
		ray->hit.normal = pl->normal;
		ray->hit.color = pl->color;
		ray->hit.type = PLANE;
		ray->hit.object = pl;
		(*a) = true;
	}
}

void	plane_intersect(t_all **all, t_ray *ray, bool *a)
{
	double	hit;
	double	parallel;
	t_list	*planes;
	t_plane	*tmp;

	planes = (*all)->world->planes;
	while (planes != NULL)
	{
		tmp = planes->content;
		parallel = dot_v3(ray->direction, tmp->normal);
		if (parallel != 0)
		{
			change_plane_hit(tmp, ray, parallel, a);
		}
		planes = planes->next;
	}
}
