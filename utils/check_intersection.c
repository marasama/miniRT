/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:52:23 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/27 02:45:18 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void    sphere_intersect(t_all **all, int x, int y, t_ray vector)
{
    t_list      *sphere_list;
    t_sphere    *tmp;
    double      radius;
    double      dot_a;
    double      dot_b;
    double      determinant;

    sphere_list = (*all)->world->spheres;
    while (sphere_list != NULL)
    {
        tmp = sphere_list->content;
        dot_a = dot_v3(vector.origin, vector.origin);
        dot_b = dot_v3(vector.direction, vector.direction);
        if (((dot_b * dot_b) - 4 * dot_a * tmp->diameter) >= 0)
            set_color(all, x, y, 1);
        else
            set_color(all, x, y, 0);
        sphere_list = sphere_list->next;
    }
}