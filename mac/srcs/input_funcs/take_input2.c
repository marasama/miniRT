/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:20:29 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/25 18:21:38 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	take_color(t_all **all, const char *a, char *b)
{
	t_color	color;
	char	**digits;

	digits = ft_split(a, ',');
	if (!digits || !digits[0] || !digits[1] || !digits[2] || digits[3])
	{
		free_words(digits);
		print_error(all, 0);
	}
	color.red = clamp(ft_atoi(digits[0]), 255, 0);
	color.green = clamp(ft_atoi(digits[1]), 255, 0);
	color.blue = clamp(ft_atoi(digits[2]), 255, 0);
	free_words(digits);
	return (color_to_int(color));
}

t_v3	take_v3(t_all **all, const char *a, char *b)
{
	char	**digits;
	t_v3	v;

	digits = ft_split(a, ',');
	if (!digits || !digits[0] || !digits[1] || !digits[2] || digits[3])
	{
		free(b);
		free_words(digits);
		print_error(all, 0);
	}
	v.x = ft_strtod(digits[0]);
	v.y = ft_strtod(digits[1]);
	v.z = ft_strtod(digits[2]);
	free_words(digits);
	return (v);
}

void	set_camera(t_all **all, char **words, int count, char *a)
{
	if (count != 4)
	{
		free(a);
		free_words(words);
		print_error(all, 0);
	}
	if ((*all)->world->camera != NULL)
	{
		free(a);
		free_words(words);
		print_error(all, 5);
	}
	(*all)->world->camera = (t_camera *)malloc(sizeof(t_camera));
	if ((*all)->world->camera == NULL)
	{
		free(a);
		free_words(words);
		print_error(all, 4);
	}
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew((*all)->world->camera));
	(*all)->world->camera->normal = take_v3(all, words[2], a);
	(*all)->world->camera->normal = check_nor(&(*all)->world->camera->normal);
	(*all)->world->camera->cordnts = take_v3(all, words[1], a);
	(*all)->world->camera->fov = clamp(ft_strtod(words[3]), 180, 0);
	print_camera((*all)->world->camera);
}

void	set_ambient(t_all **all, char **words, int count, char *a)
{
	if (count != 3)
	{
		free(a);
		free_words(words);
		print_error(all, 0);
	}
	if ((*all)->world->ambient != NULL)
	{
		free(a);
		free_words(words);
		print_error(all, 5);
	}
	(*all)->world->ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if ((*all)->world->ambient == NULL)
	{
		free(a);
		free_words(words);
		print_error(all, 4);
	}
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew((*all)->world->ambient));
	(*all)->world->ambient->l_ratio = ft_strtod(words[1]);
	(*all)->world->ambient->color = take_color(all, words[2], a);
	print_ambient((*all)->world->ambient);
}

void	set_light(t_all **all, char **words, int count, char *a)
{
	if (count != 4)
	{
		free(a);
		free_words(words);
		print_error(all, 0);
	}
	if ((*all)->world->light != NULL)
	{
		free(a);
		free_words(words);
		print_error(all, 4);
	}
	(*all)->world->light = (t_light *)malloc(sizeof(t_light));
	if ((*all)->world->light == NULL)
	{
		free(a);
		free_words(words);
		print_error(all, 4);
	}
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew((*all)->world->light));
	(*all)->world->light->cordnts = take_v3(all, words[1], a);
	(*all)->world->light->brightness = ft_strtod(words[2]);
	(*all)->world->light->color = take_color(all, words[3], a);
	print_light((*all)->world->light);
}
