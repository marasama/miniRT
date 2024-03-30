/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:21:09 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/30 18:47:29 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	take_coordinate(const char *a, int *b, t_v3 *coordinates)
{
	ft_isws(a, b, 0);
	take_v3(a + *b, coordinates);
	while ((ft_isdigit(a[*b]) || a[*b] == '.' || a[*b] == '-' || a[*b] == '+'
			|| a[*b] == ',') && a[*b])
		(*b)++;
}

void	take_double(const char *a, int *b, double *data)
{
	ft_isws(a, b, 0);
	*data = ft_strtod(a + *b);
	while ((ft_isdigit(a[*b]) || a[*b] == '.' || a[*b] == '-' || a[*b] == '+'
			|| a[*b] == ',') && a[*b])
		(*b)++;
}

void	set_sphere(t_all **all, const char *a)
{
	int			b;
	t_sphere	*new_sphere;

	new_sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!new_sphere)
		print_error(all, 4);
	ft_lstadd_front(&(*all)->world->spheres, ft_lstnew(new_sphere));
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew(new_sphere));
	b = 0;
	ft_isws(a, &b, 0);
	b += 2;
	ft_isws(a, &b, 0);
	take_v3(a + b, &(new_sphere->cordnts));
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	new_sphere->diameter = ft_strtod(a + b);
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	take_color(a + b, &(new_sphere->color));
	print_sphere(new_sphere);
}

void	set_plane(t_all **all, const char *a)
{
	int		b;
	t_plane	*new_plane;

	new_plane = (t_plane *)malloc(sizeof(t_plane));
	if (!new_plane)
		print_error(all, 4);
	ft_lstadd_front(&(*all)->world->planes, ft_lstnew(new_plane));
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew(new_plane));
	b = 0;
	ft_isws(a, &b, 0);
	b += 2;
	take_coordinate(a, &b, &(new_plane->cordnts));
	ft_isws(a, &b, 0);
	take_v3(a + b, &(new_plane->normal));
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	take_color(a + b, &(new_plane->color));
	print_plane(new_plane);
}

void	set_cylinder(t_all **all, const char *a)
{
	int			b;
	t_cylinder	*new_cylinder;

	new_cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!new_cylinder)
		print_error(all, 4);
	ft_lstadd_front(&(*all)->world->cylinders, ft_lstnew(new_cylinder));
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew(new_cylinder));
	b = 0;
	ft_isws(a, &b, 0);
	b += 2;
	take_coordinate(a, &b, &(new_cylinder->cordnts));
	take_coordinate(a, &b, &(new_cylinder->normal));
	take_double(a, &b, &(new_cylinder->diameter));
	take_double(a, &b, &(new_cylinder->height));
	ft_isws(a, &b, 0);
	take_color(a + b, &(new_cylinder->color));
	print_cylinder(new_cylinder);
}
