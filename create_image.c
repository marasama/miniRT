/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:11:50 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/27 02:58:47 by adurusoy         ###   ########.fr       */
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

void    check_intersection(t_all **all, int x, int y, t_ray tmp)
{
    if ((*all)->world->spheres != NULL)
        sphere_intersect(all, x, y, tmp);
}

void	set_color(t_all **all, int x, int y, int opt)
{
    int     index;

	index = ((*all)->mlx->size_line * y) + (x * ((*all)->mlx->bpp / 8));
    if (opt == 1)
    {
	    (*all)->mlx->pixels[index] = 170;
    	(*all)->mlx->pixels[index + 1] = 254;
	    (*all)->mlx->pixels[index + 2] = 0;
    	(*all)->mlx->pixels[index + 3] = 0;
    }
    else
    {
        (*all)->mlx->pixels[index] = 34;
    	(*all)->mlx->pixels[index + 1] = 51;
	    (*all)->mlx->pixels[index + 2] = 235;
    	(*all)->mlx->pixels[index + 3] = 0;
    }
}

double  degree_to_radian(double degree)
{
    return (degree * (3.14159 / 180));
}

t_ray make_ray(const t_camera* camera, int x, int y) {
  // Calculate view plane dimensions based on focal length and FOV
  double focal_length = 1;
  double theta = degree_to_radian(camera->fov);
  double half_tan_theta = tan(theta / 2.0);
  double view_height = 2.0 * half_tan_theta * focal_length;
  double view_width = view_height * ((double)WIDTH / HEIGHT);

  // Define view plane basis vectors (assuming right-handed coordinate system)
  t_v3 view_right = normalize_v3(create_vector(view_width, 0.0, 0.0));
  t_v3 view_up = normalize_v3(create_vector(0.0, view_height, 0.0));

  // Assuming camera look_at direction is normalized
  t_v3 look_dir = normalize_v3((camera->normal));

  // Calculate the forward vector based on camera position and look-at direction
  t_v3 forward = subtract_v3((camera->cordnts), look_dir);
  forward = normalize_v3(forward);

  // Right vector perpendicular to both forward and up vectors
  t_v3 right = cross_v3(&forward, &view_up);
  right = normalize_v3(right);

  // Recalculate viewUp based on the right vector for a complete orthonormal basis
  view_up = cross_v3(&right, &forward);
  view_up = normalize_v3(view_up);

  // Calculate pixel steps in view plane
  t_v3 pixel_step_x = scale_v3(right, 1.0 / (double)WIDTH);
  t_v3 pixel_step_y = scale_v3(view_up, 1.0 / (double)HEIGHT);

  // Top-left corner of the view plane (assuming camera looks in -z direction)
  t_v3 top_left = subtract_v3((camera->cordnts), scale_v3(view_up, focal_length));
  top_left = subtract_v3(top_left, scale_v3(add_v3(right, view_up), 0.5));

  // Center of the top-left pixel
  t_v3 pixel_center = add_v3(top_left, add_v3(pixel_step_x, pixel_step_y));

  // Specific pixel location based on (x, y) coordinates
  t_v3 pixel_coord = add_v3(pixel_center, add_v3(scale_v3(pixel_step_x, x), scale_v3(pixel_step_y, y)));

  // Ray direction from camera to pixel
  t_v3 ray_dir = subtract_v3(pixel_coord, (camera->cordnts));
  ray_dir = normalize_v3(ray_dir);

  // Create and return the ray (origin is camera position)
  t_ray ray;
  ray.origin = camera->cordnts;
  ray.direction = ray_dir;
  return (ray);
}

void    create_everything(t_all **all)
{
    int         x;
    int         y;
    t_ray       tmp;

    y = 0;
    mlx_clear_window((*all)->mlx->ptr, (*all)->mlx->window);
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            tmp = make_ray((*all)->world->camera, x, y);
            check_intersection(all, x, y, tmp);
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