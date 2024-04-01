/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:52:23 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/01 07:35:02 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	calc_roots(t_sphere *sp, t_ray *ray, double *roots, bool *a)
{
	t_v3	v2sp;
	double	dot_a;
	double	dot_b;
	double	dot_c;
	int		i;

	i = 0;
	v2sp = subtract_v3(ray->origin, sp->cordnts);
	dot_a = dot_v3(ray->direction, ray->direction);
	dot_b = dot_v3(v2sp, ray->direction) * 2.0f;
	dot_c = dot_v3(v2sp, v2sp) - (sp->diameter * sp->diameter / 4.0f);
	roots[0] = (-dot_b - sqrt(dot_b * dot_b - dot_a * dot_c * 4.0f)) / (dot_a * 2);
	roots[1] = (-dot_b + sqrt(dot_b * dot_b - dot_a * dot_c * 4.0f)) / (dot_a * 2);
	while (i < 2)
	{
		if (roots[i] < ray->hit.hitNum)
		{
				ray->hit.hitNum = roots[i];
				ray->hit.hitPoint = add_v3(ray->origin, scale_v3(ray->direction, roots[i]));
				ray->hit.normal = normalize(subtract_v3(ray->hit.hitPoint, sp->cordnts));
				ray->hit.color = colorToInt(sp->color);
				ray->hit.type = SPHERE;
				*a = true;
				/* ray->hit.hitPoint = normalize(ray->hit.hitPoint);
				ray->color.green = ray->hit.hitPoint.x * 255;
				ray->color.blue = ray->hit.hitPoint.y * 255;
				ray->color.red = ray->hit.hitPoint.z * 255; */
		}
		i++;
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
		calc_roots(tmp, ray, roots, a);
		sphere_list = sphere_list->next;
	}
}
