/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:52:23 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/31 07:46:42 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	calc_discriminant(t_sphere *sp, t_ray *ray)
{
	t_v3	v2sp;
	double	dot_a;
	double	dot_b;
	double	dot_c;
	double	root1;

	v2sp = subtract_v3(ray->origin, sp->cordnts);
	dot_a = dot_v3(ray->direction, ray->direction);
	dot_b = dot_v3(v2sp, ray->direction) * 2.0f;
	dot_c = dot_v3(v2sp, v2sp) - (sp->diameter * sp->diameter / 4.0f);
	root1 = (-dot_b - sqrt(dot_b * dot_b - dot_a * dot_c * 4.0f)) / (dot_a * 2);
	if ((root1) < ray->hit)
	{
		ray->hit = root1;
		ray->color = sp->color;
	}
}

void	sphere_intersect(t_all **all, int x, int y, t_ray *ray)
{
	t_list		*sphere_list;
	t_sphere	*tmp;

	sphere_list = (*all)->world->spheres;
	while (sphere_list != NULL)
	{
		tmp = sphere_list->content;
		calc_discriminant(tmp, ray);
		sphere_list = sphere_list->next;
	}
}
