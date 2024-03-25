/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:11:50 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/25 18:27:42 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     destroy_exit(t_all **all)
{
    mlx_destroy_image((*all)->mlx->ptr, (*all)->mlx->image);
    mlx_destroy_window((*all)->mlx->ptr, (*all)->mlx->window);
    free_everything(&((*all)->mallocs));
    exit(0);
}

void	set_color(t_all **all, int x, int y)
{
    int     index;

	index = ((*all)->mlx->size_line * y) + (x * ((*all)->mlx->bpp / 8));
	(*all)->mlx->pixels[index] = x * y + x;
	(*all)->mlx->pixels[index + 1] = x * y + x;
	(*all)->mlx->pixels[index + 2] = x * y + x;
	(*all)->mlx->pixels[index + 3] = 0;
}

void    create_everything(t_all **all)
{
    int     x;
    int     y;

    y = 0;
    mlx_clear_window((*all)->mlx->ptr, (*all)->mlx->window);
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            set_color(all, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window((*all)->mlx->ptr, (*all)->mlx->window,
            (*all)->mlx->image, 0, 0);
}

void    key_hooks(t_all **all)
{
    mlx_hook((*all)->mlx->window, 53, 1, destroy_exit, all);
    mlx_hook((*all)->mlx->window, 17, 1, destroy_exit, all);
    mlx_loop((*all)->mlx->ptr);
}