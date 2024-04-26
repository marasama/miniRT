/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:45:39 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/26 21:45:49 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <stdio.h>

int	destroy_exit(t_all **all)
{
	if ((*all)->mlx->image)
		mlx_destroy_image((*all)->mlx->ptr, (*all)->mlx->image);
	if ((*all)->mlx->window)
		mlx_destroy_window((*all)->mlx->ptr, (*all)->mlx->window);
	free_list(&(*all)->world->planes);
	free_list(&(*all)->world->spheres);
	free_list(&(*all)->world->cylinders);
	free_list(&(*all)->mallocs);
	free(*all);
	exit(0);
}

int	key_press(int keycode, t_all **all)
{
	if (keycode == ESC)
		destroy_exit(all);
	else if (keycode == UP_ARROW)
	{
		printf("UP \n");
		(*all)->world->camera->cordnts.y += 0.5;
		create_everything(all);
	}
	else if (keycode == DOWN_ARROW)
	{
		printf("DOWN \n");
		(*all)->world->camera->cordnts.y -= 0.5;
		create_everything(all);
	}
	else if (keycode == LEFT_ARROW)
	{
		printf("LEFT \n");
		(*all)->world->camera->cordnts.x -= 0.5;
		create_everything(all);
	}
	else
		key_press2(keycode, all);
	return (1);
}

int	clamp(int x, int max, int min)
{
	if (x >= max)
		return (max);
	else if (x <= min)
		return (min);
	return (x);
}
