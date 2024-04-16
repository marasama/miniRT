/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:11:50 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/16 15:40:54 by adurusoy         ###   ########.fr       */
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
	tmp.hit.hit_len = INFINITY;
	tmp.hit.object = NULL;
	return (tmp);
}

t_ray	gen_ray(t_all **all, int x, int y)
{
	float	pixel[2];

	pixel[0] = ((2.0f * ((float)x)) / WIDTH) - 1;
	pixel[1] = ((2.0f * ((float)y)) / HEIGHT) - 1;
	return (make_ray((*all)->world->camera, pixel));
}

void	init_cam(t_camera *cam)
{
	t_v3	tmp;

	cam->props.w = normalize(cross_v3(cam->normal, (t_v3){0, 1, 0}));
	cam->props.u = normalize(cross_v3(cam->normal, cam->props.w));
	cam->props.w = normalize(cross_v3(cam->normal, cam->props.u));
}

int	put_background(int y)
{
	t_color	a;
	double	intensity;
	double	norm;

	norm = ((2.0f * ((float)y)) / HEIGHT) - 1;
	a.red = 115;
	a.green = 215;
	a.blue = 255;
	intensity = 1 - (double)abs(y) / (double)HEIGHT;
	intensity = (double)abs(intensity);
	a.red *= intensity;
	a.green *= intensity;
	a.blue *= intensity;
	return (color_to_int(a));
}

void	create_everything(t_all **all)
{
	int		x;
	int		y;
	t_ray	tmp;
	t_v3	convert;
	int		color;

	y = -1;
	init_cam((*all)->world->camera);
	mlx_clear_window((*all)->mlx->ptr, (*all)->mlx->window);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			tmp = gen_ray(all, x, y);
			if (!check_intersection(all, &tmp))
				color = put_background(tmp.direction.y);
			else
				color = re_color(all, &tmp);
			set_color(all, x, y, int_to_color(color));
		}
	}
	mlx_put_image_to_window((*all)->mlx->ptr, (*all)->mlx->window,
		(*all)->mlx->image, 0, 0);
	printf("zort\n");
}
