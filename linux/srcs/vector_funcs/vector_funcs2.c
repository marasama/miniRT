/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:29:03 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/25 17:54:53 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <math.h>

double	dot_v3(t_v3 a, t_v3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double	len_v3(t_v3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_v3	normalize(t_v3 v)
{
	return (scale_v3(v, 1 / len_v3(v)));
}

t_v3	create_vector(double x, double y, double z)
{
	t_v3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}
