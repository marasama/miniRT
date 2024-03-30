/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:52:23 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/30 13:34:34 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int     calc_discriminant(t_sphere *sp, t_ray *ray)
{
    t_v3        v2sp;
    double      dot_a;
    double      dot_b;
    double      dot_c;
    double      discriminant;

    v2sp = subtract_v3(ray->origin, sp->cordnts);
    dot_a = dot_v3(ray->direction, ray->direction);
    dot_b = dot_v3(v2sp, ray->direction);
    dot_c = dot_v3(v2sp, v2sp) - sp->diameter * sp->diameter / 4.0;
    discriminant = dot_b * dot_b - dot_a * dot_c;
    if (discriminant >= 0)
        return (1);
    return (0);
}

void    sphere_intersect(t_all **all, int x, int y, t_ray *ray)
{
    t_list      *sphere_list;
    t_sphere    *tmp;

    sphere_list = (*all)->world->spheres;
    while (sphere_list != NULL)
    {
        tmp = sphere_list->content;
        if (calc_discriminant(tmp, ray))
            ray->color = tmp->color;
        sphere_list = sphere_list->next;
    }
}