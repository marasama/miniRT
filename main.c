/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:17:45 by adurusoy          #+#    #+#             */
/*   Updated: 2024/01/08 16:17:31 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>
#include <stdio.h>

int check_args(int argc, char **argv)
{
	char	*a;

	if (argc != 2)
		return (0);
	a = strrchr(argv[1], '.');
	if (*(a + 1) != 'r' || *(a + 2) != 't')
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_mlx	*all;

	if (check_args(argc, argv))
	{
		all->mlx = mlx_init();
		all->window = mlx_new_window(all->mlx, WIDTH,
					HEIGHT, "Mini RayTracing");
		all->image = mlx_new_image(all->mlx, WIDTH, HEIGHT);
		all->pixels = (unsigned char *)mlx_get_data_addr(all->image,
					&all->bpp, &all->size_line, &all->endian);
	}
	else
		printf("Argument Error\n");
}
