/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:39:47 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/25 17:42:33 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	check_intersection(t_all **all, t_ray *tmp)
{
	bool	hit;

	hit = false;
	if ((*all)->world->spheres != NULL)
		sphere_intersect(all, tmp, &hit);
	if ((*all)->world->planes != NULL)
		plane_intersect(all, tmp, &hit);
	if ((*all)->world->cylinders != NULL)
		cylinder_intersect((*all)->world->cylinders, tmp, &hit);
	if (hit == true && dot_v3(tmp->hit.normal, tmp->direction) >= 0)
		tmp->hit.normal = scale_v3(tmp->hit.normal, -1);
	return (hit);
}
