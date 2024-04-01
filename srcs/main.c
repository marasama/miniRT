/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:17:45 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/31 15:25:20 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdio.h>

void	init_all(t_all **all)
{
	(*all)->mlx = NULL;
	(*all)->mallocs = NULL;
	(*all)->world = (t_world *)malloc(sizeof(t_world));
	if (!(*all)->world)
		print_error(all, 4);
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew((*all)->world));
	(*all)->world->camera = NULL;
	(*all)->world->ambient = NULL;
	(*all)->world->light = NULL;
	(*all)->world->planes = NULL;
	(*all)->world->cylinders = NULL;
	(*all)->world->spheres = NULL;
}

void	init_mlx(t_all **all)
{
	(*all)->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!(*all)->mlx)
		print_error(all, 4);
	ft_lstadd_front(&(*all)->mallocs, ft_lstnew((*all)->mlx));
	(*all)->mlx->ptr = mlx_init();
	(*all)->mlx->window = mlx_new_window((*all)->mlx->ptr, WIDTH, HEIGHT,
			"Humble RayTracing Engine");
	(*all)->mlx->image = mlx_new_image((*all)->mlx->ptr, WIDTH, HEIGHT);
	(*all)->mlx->pixels = (unsigned char *)mlx_get_data_addr((*all)->mlx->image,
			&(*all)->mlx->bpp, &(*all)->mlx->size_line, &(*all)->mlx->endian);
	create_everything(all);
	key_hooks(all);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (1);
	init_all(&all);
	check_args(&all, argc, argv);
	init_mlx(&all);
	return (0);
}
