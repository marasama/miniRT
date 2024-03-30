/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:39:47 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/30 18:51:31 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	check_intersection(t_all **all, int x, int y, t_ray *tmp)
{
	if ((*all)->world->spheres != NULL)
		sphere_intersect(all, x, y, tmp);
}
