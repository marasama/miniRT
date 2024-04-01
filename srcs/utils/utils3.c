/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:41:10 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/01 10:25:33 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <stdio.h>

void	key_hooks(t_all **all)
{
	mlx_hook((*all)->mlx->window, CROSS, 1, destroy_exit, all);
	mlx_hook((*all)->mlx->window, 2, 1, key_press, all);
	mlx_loop((*all)->mlx->ptr);
}

int	key_press2(int keycode, t_all **all)
{
	if (keycode == RIGHT_ARROW)
	{
		printf("RIGHT \n");
		(*all)->world->camera->cordnts.x += 0.5;
		create_everything(all);
	}
}
