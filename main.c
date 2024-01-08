/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:17:45 by adurusoy          #+#    #+#             */
/*   Updated: 2024/01/08 14:31:42 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char *argv)
{
	t_mlx	*all;
	all->mlx = mlx_init;
	all->window = mlx_new_window(all->mlx, WIDTH, HEIGHT, "Mini Ray Tracing");
	all->image = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	mlx_put_image_to_window(all->mlx, all->window, all->image, WIDTH, HEIGHT);
}
