/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:21:09 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/17 13:03:49 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	set_sphere(t_all **all, char **words, int count)
{
	t_sphere	*new_sphere;

	if (count != 4)
	{
		free_words(words);
		print_error(all, 0);
	}
	new_sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!new_sphere)
	{
		free_words(words);
		print_error(all, 4);
	}
	ft_lstadd_front(&(*all)->world->spheres, ft_lstnew(new_sphere));
	new_sphere->cordnts = take_v3(all, words[1]);
	new_sphere->diameter = ft_strtod(words[2]);
	new_sphere->color = take_color(all, words[3]);
	print_sphere(new_sphere);
}

void	set_plane(t_all **all, char **words, int count)
{
	t_plane	*new_plane;

	if (count != 4)
	{
		free_words(words);
		print_error(all, 0);
	}
	new_plane = (t_plane *)malloc(sizeof(t_plane));
	if (!new_plane)
	{
		free_words(words);
		print_error(all, 4);
	}
	ft_lstadd_front(&(*all)->world->planes, ft_lstnew(new_plane));
	new_plane->cordnts = take_v3(all, words[1]);
	new_plane->normal = normalize(take_v3(all, words[2]));
	new_plane->color = take_color(all, words[3]);
	print_plane(new_plane);
}

void	set_cylinder(t_all **all, char **words, int count)
{
	int			b;
	t_cylinder	*new_cylinder;

	if (count != 6)
	{
		free_words(words);
		print_error(all, 0);
	}
	new_cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!new_cylinder)
	{
		free_words(words);
		print_error(all, 4);
	}
	ft_lstadd_front(&(*all)->world->cylinders, ft_lstnew(new_cylinder));
	new_cylinder->cordnts = take_v3(all, words[1]);
	new_cylinder->normal = normalize(take_v3(all, words[2]));
	new_cylinder->diameter = ft_strtod(words[3]);
	new_cylinder->height = ft_strtod(words[4]);
	new_cylinder->color = take_color(all, words[5]);
	print_cylinder(new_cylinder);
}
