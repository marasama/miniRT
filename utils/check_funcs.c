/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:08:01 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/25 01:19:29 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdio.h>

void	check_objects(t_all **all, const char *a)
{
	int		c;

	c = 0;
	ft_isws(a, &c, 0);
	if (a[c] == 'C' && ft_isws(a, &c, 1))
		set_camera(all, a);
	else if (a[c] == 'A' && ft_isws(a, &c, 1))
		set_ambient(all, a);
	else if (a[c] == 'L' && ft_isws(a, &c, 1))
		set_light(all, a);
	else if ((a[c] == 's' && a[c + 1] == 'p') && (a[c + 2] == '\t' || a[c + 2] == ' '))
		set_sphere(all, a);
	else if ((a[c] == 'p' && a[c + 1] == 'l') && (a[c + 2] == '\t' || a[c + 2] == ' '))
		set_plane(all, a);
	else if ((a[c] == 'c' && a[c + 1] == 'y') && (a[c + 2] == '\t' || a[c + 2] == ' '))
		set_cylinder(all, a);
	else
		printf("%s", a);
}
