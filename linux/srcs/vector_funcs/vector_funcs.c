/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:44:14 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/30 18:46:07 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_v3	add_v3(t_v3 a, t_v3 b)
{
	return (create_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_v3	subtract_v3(t_v3 a, t_v3 b)
{
	return (create_vector(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_v3	add_num_v3(t_v3 a, double b)
{
	return (create_vector(a.x + b, a.y + b, a.z + b));
}

t_v3	subtract_num_v3(t_v3 a, double b)
{
	return (create_vector(a.x - b, a.y - b, a.z - b));
}

t_v3	scale_v3(t_v3 a, double b)
{
	return (create_vector(a.x * b, a.y * b, a.z * b));
}
