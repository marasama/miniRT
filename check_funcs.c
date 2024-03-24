/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:08:01 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/24 03:20:18 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	print_camera(t_camera *asd)
{
	printf("---------CAMERA---------\n");
	printf("%f , %f , %f\n", asd->coordinates.x, asd->coordinates.y, asd->coordinates.z);
	printf("%f , %f , %f\n", asd->orientation.x, asd->orientation.y, asd->orientation.z);
	printf("%f\n", asd->fov);
	printf("------------------------\n");
}

void	print_ambient(t_ambient *asd)
{
	printf("--------AMBIENT---------\n");
	printf("%f\n", asd->l_ratio);
	printf("%d , %d , %d\n", asd->color.red, asd->color.green, asd->color.blue);
	printf("------------------------\n");
}

void	print_light(t_light *asd)
{
	printf("----------LIGHT----------\n");
	printf("%f\n", asd->brightness);
	printf("%d , %d , %d\n", asd->color.red, asd->color.green, asd->color.blue);
	printf("%f , %f , %f\n", asd->coordinates.x, asd->coordinates.y, asd->coordinates.z);
	printf("------------------------\n");
}

void	print_plane(t_plane *asd)
{
	printf("----------PLANE----------\n");
	printf("%d , %d , %d\n", asd->color.red, asd->color.green, asd->color.blue);
	printf("%f , %f , %f\n", asd->coordinates.x, asd->coordinates.y, asd->coordinates.z);
	printf("%f , %f , %f\n", asd->normal.x, asd->normal.y, asd->normal.z);
	printf("------------------------\n");
}




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

void	check_camera(t_all **all, const char *a)
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

void	check_ambient(t_all **all, const char *a)
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

void	check_light(t_all **all, const char *a)
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

void	check_plane(t_all **all, const char *a)
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
	ft_isws(a, &b, 0);
	take_v3(a + b, &(new_plane->coordinates));
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	take_v3(a + b, &(new_plane->normal));
	while ((ft_isdigit(a[b]) || a[b] == '.' || a[b] == '-' || a[b] == '+'
			|| a[b] == ',') && a[b])
		b++;
	ft_isws(a, &b, 0);
	take_color(a + b, &(new_plane->color));
	print_plane(new_plane);
}

void	check_objects(t_all **all, const char *a, int *b)
{
	int		c;

	c = 0;
	ft_isws(a, &c, 0);
	if (a[c] == 'C' && ft_isws(a, &c, 1))
		check_camera(all, a);
	else if (a[c] == 'A' && ft_isws(a, &c, 1))
		check_ambient(all, a);
	else if (a[c] == 'L' && ft_isws(a, &c, 1))
		check_light(all, a);
	else if ((a[c] == 'p' && a[c + 1] == 'l') && ft_isws(a, &c, 1))
		check_plane(all, a);
	else
		printf("%s", a);
}
