/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:20:29 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/25 01:10:28 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	take_color(const char *a, t_color *rgb)
{
	int	b;

	b = 0;
	rgb->red = ft_atoi(a);
	while (ft_isdigit(a[b]))
		b++;
	b++;
	rgb->green = ft_atoi(a + b);
	while (ft_isdigit(a[b]))
		b++;
	b++;
	rgb->blue = ft_atoi(a + b);
}

void	take_v3(const char *a, t_vector *v3)
{
	int		b;

	b = 0;
	v3->x = ft_strtod(a);
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+')
		&& a[b])
		b++;
	a += b + 1;
	b = 0;
	v3->y = ft_strtod(a);
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+')
		&& a[b])
		b++;
	a += b + 1;
	b = 0;
	v3->z = ft_strtod(a);
}

void	set_camera(t_all **all, const char *a)
{
	int		b;

	if ((*all)->world->camera != NULL)
		print_error(all, 5);
	(*all)->world->camera = (t_camera *)malloc(sizeof(t_camera));
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew((*all)->world->camera));
	b = 0;
	ft_isws(a, &b, 0);
	b++;
	ft_isws(a, &b, 0);
	take_v3(a + b, &((*all)->world->camera->coordinates));
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	take_v3(a + b, &((*all)->world->camera->orientation));
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	(*all)->world->camera->fov = ft_strtod(a + b);
	print_camera((*all)->world->camera);
}

void	set_ambient(t_all **all, const char *a)
{
	int		b;

	if ((*all)->world->ambient != NULL)
		print_error(all, 5);
	(*all)->world->ambient = (t_ambient *)malloc(sizeof(t_ambient));
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew((*all)->world->ambient));
	b = 0;
	ft_isws(a, &b, 0);
	b++;
	ft_isws(a, &b, 0);
	(*all)->world->ambient->l_ratio = ft_strtod(a + b);
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	take_color(a + b, &((*all)->world->ambient->color));
	print_ambient((*all)->world->ambient);
}

void	set_light(t_all **all, const char *a)
{
	int		b;

	if ((*all)->world->light != NULL)
		print_error(all, 5);
	(*all)->world->light = (t_light *)malloc(sizeof(t_light));
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew((*all)->world->light));
	b = 0;
	ft_isws(a, &b, 0);
	b++;
	ft_isws(a, &b, 0);
	take_v3(a + b, &((*all)->world->light->coordinates));
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	(*all)->world->light->brightness = ft_strtod(a + b);
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	take_color(a + b, &((*all)->world->light->color));
	print_light((*all)->world->light);
}