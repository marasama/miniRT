/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:45:39 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/01 03:06:57 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <stdio.h>

int	destroy_exit(t_all **all)
{
	mlx_destroy_image((*all)->mlx->ptr, (*all)->mlx->image);
	mlx_destroy_window((*all)->mlx->ptr, (*all)->mlx->window);
	free_everything(&((*all)->mallocs));
	free(*all);
	exit(0);
}

int	key_press(int keycode, t_all **all)
{
	if (keycode == ESC)
	{
		printf("ESC \n");
		destroy_exit(all);
	}
	else if (keycode == UP_ARROW)
	{
		printf("UP \n");
		(*all)->world->camera->cordnts.y += 0.5;
	}
	else if (keycode == DOWN_ARROW)
	{
		printf("DOWN \n");
		(*all)->world->camera->cordnts.y -= 0.5;
	}
	else if (keycode == LEFT_ARROW)
	{
		printf("LEFT \n");
		(*all)->world->camera->cordnts.x -= 0.5;
	}
	else if (keycode == RIGHT_ARROW)
	{
		printf("RIGHT \n");
		(*all)->world->camera->cordnts.x += 0.5;
	}
	create_everything(all);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

int	clamp(int x)
{
	if (x > 255)
		return (255);
	else if (x < 0)
		return (0);
	return (x);
}