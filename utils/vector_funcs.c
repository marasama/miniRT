/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:44:14 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/30 03:58:13 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_v3    add_v3(t_v3 a, t_v3 b)
{
    return (create_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_v3    subtract_v3(t_v3 a, t_v3 b)
{
    return (create_vector(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_v3    add_num_v3(t_v3 a, double  b)
{
    return (create_vector(a.x + b, a.y + b, a.z + b));
}

t_v3    subtract_num_v3(t_v3 a, double  b)
{
    return (create_vector(a.x - b, a.y - b, a.z - b));
}

t_v3    scale_v3(t_v3 a, double  b)
{
    return (create_vector(a.x * b, a.y * b, a.z * b));
}

t_v3    divide_v3(t_v3 a, double  b)
{
    return (scale_v3(a, 1 / b));
}

double  dot_v3(t_v3 a, t_v3 b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double		len_v3(t_v3 a)
{
	return (sqrt(dot_v3(a, a)));
}

t_v3 normalize(t_v3 v)
{
    return (scale_v3(v, 1 / len_v3(v)));
}

t_v3 cross_v3(const t_v3 vec1, const t_v3 vec2)
{
  t_v3 result;

  result.x = vec1.y * vec2.z - vec1.z * vec2.y;
  result.y = vec1.z * vec2.x - vec1.x * vec2.z;
  result.z = vec1.x * vec2.y - vec1.y * vec2.x;
  return result;
}

t_v3 create_vector(double x, double y, double z)
{
  t_v3 v;
  v.x = x;
  v.y = y;
  v.z = z;
  return v;
}