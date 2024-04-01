/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:11:50 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/01 08:17:04 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <stdio.h>

t_ray	make_ray(t_camera *cam, float *pixel)
{
	t_ray	tmp;
	t_v3	vertical;
	t_v3	horizantal;
	double	hview;
	double	vview;

	vview = tan((cam->fov / 2) * PI / 180);
	hview = vview / ((float)WIDTH / (float)HEIGHT);
	vertical = scale_v3(cam->props.u, pixel[1] * hview);
	horizantal = scale_v3(cam->props.w, pixel[0] * vview);
	tmp.direction = add_v3(vertical, horizantal);
	tmp.direction = add_v3(tmp.direction, cam->normal);
	tmp.direction = add_v3(tmp.direction, cam->cordnts);
	tmp.origin = cam->cordnts;
	tmp.direction = normalize(subtract_v3(tmp.direction, tmp.origin));
	tmp.hit.color = 0;
	tmp.hit.hitNum = INFINITY;
	tmp.hit.object = NULL;
	return (tmp);
}

void	init_cam(t_camera *cam)
{
	t_v3	tmp;

	cam->props.w = normalize(cross_v3(cam->normal, (t_v3){0, 1, 0}));
	cam->props.u = normalize(cross_v3(cam->normal, cam->props.w));
	cam->props.w = normalize(cross_v3(cam->normal, cam->props.u));
}

bool	check_shadow(t_all **all, t_light *light, t_hit hit)
{
	t_ray	shadow;

	shadow.origin = add_v3(hit.hitPoint, scale_v3(hit.normal, 0.0001));
	shadow.direction = normalize(subtract_v3(light->cordnts, shadow.origin));
	shadow.hit.object = hit.object;
	shadow.hit.hitNum = INFINITY;
	return (check_intersection(all, &shadow));
}

int	re_color(t_all **all, t_ray *ray)
{
	int		ambient;
	t_light	*light;
	int		color;
	bool	check;

	light = (*all)->world->light;
	ambient = scale_color(colorToInt((*all)->world->ambient->color), (*all)->world->ambient->l_ratio);
	color = color_product(ray->hit.color, ambient);
	check = check_shadow(all, light, ray->hit);
	color = add_color(color, check * color_comp(*light, ray->hit));
	return (color);
}

void	create_everything(t_all **all)
{
	int		x;
	int		y;
	t_ray	tmp;
	t_v3	convert;
	float	pixel[2];
	int		color;

	y = 0;
	init_cam((*all)->world->camera);
	mlx_clear_window((*all)->mlx->ptr, (*all)->mlx->window);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel[0] = ((2.0f * ((float)x)) / WIDTH) - 1;
			pixel[1] = ((2.0f * ((float)y)) / HEIGHT) - 1;
			tmp = make_ray((*all)->world->camera, pixel);
			if (!check_intersection(all, &tmp))
				color = 0;
			else
				color = re_color(all, &tmp);
			set_color(all, x, y, intToColor(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((*all)->mlx->ptr, (*all)->mlx->window,
		(*all)->mlx->image, 0, 0);
}

void	key_hooks(t_all **all)
{
	mlx_hook((*all)->mlx->window, CROSS, 1, destroy_exit, all);
	mlx_hook((*all)->mlx->window, 2, 1, key_press, all);
	mlx_loop((*all)->mlx->ptr);
}
