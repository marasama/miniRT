/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:11:50 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/30 06:37:24 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int     destroy_exit(t_all **all)
{
    mlx_destroy_image((*all)->mlx->ptr, (*all)->mlx->image);
    mlx_destroy_window((*all)->mlx->ptr, (*all)->mlx->window);
    free_everything(&((*all)->mallocs));
    exit(0);
}

void    check_intersection(t_all **all, int x, int y, t_ray *tmp)
{
    if ((*all)->world->spheres != NULL)
        sphere_intersect(all, x, y, tmp);
}

void	set_color(t_all **all, int x, int y, t_ray  *ray)
{
    int     index;

	index = ((*all)->mlx->size_line * y) + (x * ((*all)->mlx->bpp / 8));
	(*all)->mlx->pixels[index] = ray->color.red;
    (*all)->mlx->pixels[index + 1] = ray->color.green;
	(*all)->mlx->pixels[index + 2] = ray->color.blue;
    (*all)->mlx->pixels[index + 3] = 0;
}

t_ray make_ray(const t_camera *cam, int x, int y)
{
    double  pixel_x;
    double  pixel_y;
    t_ray   tmp;

    pixel_x = (2 * ((x + 0.5) / WIDTH) - 1) * tan(cam->fov * M_PI / 360);
    pixel_y = (1 - 2 * ((y + 0.5) / HEIGHT)) * tan(cam->fov * M_PI / 360);
    tmp.origin = cam->cordnts;
    tmp.direction = normalize((t_v3){pixel_x, pixel_y,1});
    tmp.color.blue = 0;
    tmp.color.red = 0;
    tmp.color.green = 0;
    return (tmp);
}

/* void    init_cam(t_camera *cam)
{
    double  view_plane[2];
    t_v3    tmp;
    t_v3    w;
    t_v3    u;
    t_v3    v;

    view_plane[0] = 2 * tan(cam->fov / 2);
    view_plane[1] = view_plane[0] * HEIGHT / WIDTH;
    w = normalize(scale_v3(cam->normal, -1));
    u = cross_v3(create_vector(0, 1, 0), w);
    v = cross_v3(w, u);
    cam->props.horizantal = scale_v3(u, view_plane[0]);
    cam->props.vertical = scale_v3(v, view_plane[1]);
    tmp = subtract_v3(cam->cordnts, scale_v3(cam->props.horizantal, 0.5));
    tmp = subtract_v3(tmp, scale_v3(cam->props.vertical, 0.5));
    tmp = subtract_v3(tmp, w);
    cam->props.lower_left = tmp;
} */

void    create_everything(t_all **all)
{
    int         x;
    int         y;
    t_ray       tmp;

    y = HEIGHT - 1;
    //init_cam((*all)->world->camera);
    mlx_clear_window((*all)->mlx->ptr, (*all)->mlx->window);
    while (y >= 0)
    {
        x = 0;
        while (x < WIDTH)
        {
            tmp = make_ray((*all)->world->camera, x, y);
            check_intersection(all, x, y, &tmp);
            set_color(all, x, y, &tmp);
            x++;
        }
        y--;
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