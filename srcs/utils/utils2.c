/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:45:39 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/30 18:51:15 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	destroy_exit(t_all **all)
{
	mlx_destroy_image((*all)->mlx->ptr, (*all)->mlx->image);
	mlx_destroy_window((*all)->mlx->ptr, (*all)->mlx->window);
	free_everything(&((*all)->mallocs));
	exit(0);
}
