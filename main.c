/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:17:45 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/18 17:39:32 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>
#include <stdio.h>

void	all_init(t_all **all)
{
	(*all)->mlx = NULL;
	(*all)->mallocs = NULL;
	(*all)->world = (t_world *)malloc(sizeof(t_world));
	if (!(*all)->world)
		print_error(all, 4);
	ft_lstadd_front((*all)->mallocs, (*all)->world);
	(*all)->world->camera = NULL;
	(*all)->world->ambient = NULL;
	(*all)->world->light = NULL;
	(*all)->world->planes = NULL;
	(*all)->world->cylinders = NULL;
	(*all)->world->spheres = NULL;
}

void	mlx_init(t_all **all)
{
	(*all)->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	(*all)->mlx->window = mlx_new_window((*all)->mlx->mlx, WIDTH, HEIGHT,
			"Humble RayTracing Engine");
	(*all)->mlx->image = mlx_new_image((*all)->mlx, WIDTH, HEIGHT);
	(*all)->mlx->pixels = (unsigned char *)mlx_get_data_addr((*all)->mlx->image,
			&(*all)->mlx->bpp, &(*all)->mlx->size_line, &(*all)->mlx->endian);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (1); 
	all_init(&all);
	check_args(&all, argc, argv);
	mlx_init(&all);
	return (0);
}
