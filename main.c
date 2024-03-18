/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:17:45 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/17 23:03:48 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

void	print_error(int opt)
{
	printf("\e[33mError\e[0m\n");
	if (opt == 0)
		printf("\e[35mWrong argument input!!!\e[0m\n");
	if (opt == 1)
		printf("\e[35mFile opening error...\e[0m\n");
	if (opt == 2)
		printf("\e[35mFile instructions are not satisfying!!\e[0m");
	exit(1);
}

void	check_args(int argc, char **argv)
{
	char	*a;
	int		b;
	int		fd;

	if (argc != 2)
		print_error(0);
	a = ft_strrchr(argv[1], '.');
	b = 0;
	if (*(a + 1) != 'r' || *(a + 2) != 't' || a == 0)
		print_error(0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(1);
	while (a != NULL)
	{
		a = ft_gnl(fd);
		check_objects(a, &b);
		free(a);
		b++;
	}
	close(fd);
	if (b < 3)
		print_error(2);
}

int	main(int argc, char **argv)
{
	t_mlx	*all;

	check_args(argc, argv);
	all = (t_mlx *)malloc(sizeof(t_mlx));
	all->mlx = mlx_init();
	all->window = mlx_new_window(all->mlx, WIDTH, HEIGHT,
			"Humble RayTracing Engine");
	all->image = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	all->pixels = (unsigned char *)mlx_get_data_addr(all->image,
			&all->bpp, &all->size_line, &all->endian);
	return (0);
}
