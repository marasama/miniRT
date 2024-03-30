/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:11:50 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/30 14:50:47 by adurusoy         ###   ########.fr       */
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

t_ray   make_ray(t_camera *cam, float x, float y)
{
    t_ray   tmp;
    t_v3    vertical;
    t_v3    horizantal;
    double  hview;
    double  vview;

    vview = tan((cam->fov / 2) * M_PI / 180);
    hview = vview / (WIDTH / HEIGHT);
    vertical = scale_v3(cam->props.u, y * hview);
    horizantal = scale_v3(cam->props.w, x * vview);
    tmp.direction = add_v3(vertical, horizantal);
    tmp.direction = add_v3(tmp.direction, cam->normal);
    tmp.direction = add_v3(tmp.direction, cam->cordnts);
    tmp.origin = cam->cordnts;
    tmp.direction = normalize(subtract_v3(tmp.direction, tmp.origin));
    tmp.color.blue = 0;
    tmp.color.red = 0;
    tmp.color.green = 0;
    return (tmp);
}

void    init_cam(t_camera *cam)
{
    t_v3    tmp;

    cam->props.w = normalize(cross_v3(cam->normal, (t_v3){0, 1, 0}));
    cam->props.u = normalize(cross_v3(cam->normal, cam->props.w));
    cam->props.w = normalize(cross_v3(cam->normal, cam->props.u));
}

void    create_everything(t_all **all)
{
    int         x;
    int         y;
    t_ray       tmp;
    t_v3        convert;

    y = 0;
    init_cam((*all)->world->camera);
    mlx_clear_window((*all)->mlx->ptr, (*all)->mlx->window);
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            float normalized_x = ((2.0f * ((float)x)) / WIDTH) - 1;
            float normalized_y = ((2.0f * ((float)y)) / HEIGHT) - 1;
            tmp = make_ray((*all)->world->camera, normalized_x, normalized_y);
            //tmp = make_ray((*all)->world->camera, x / WIDTH, y / HEIGHT);
            check_intersection(all, x, y, &tmp);
            set_color(all, x, y, &tmp);
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