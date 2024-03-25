/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:20:02 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/25 03:10:05 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdio.h>

void	print_camera(t_camera *asd)
{
	printf("---------CAMERA---------\n");
	printf("COORDINATES\n");
	printf("%f\t %f\t %f\n", asd->cordnts.x, asd->cordnts.y, asd->cordnts.z);
	printf("ORIENTATION\n");
	printf("%f\t %f\t %f\n", asd->normal.x, asd->normal.y, asd->normal.z);
	printf("FIELD OF VIEW\n");
	printf("%f\n", asd->fov);
	printf("------------------------\n");
}

void	print_ambient(t_ambient *asd)
{
	printf("--------AMBIENT---------\n");
	printf("RATIO OF LIGHT\n");
	printf("%f\n", asd->l_ratio);
	printf("COLOR\n");
	printf("%d\t %d\t %d\n", asd->color.red, asd->color.green, asd->color.blue);
	printf("------------------------\n");
}

void	print_light(t_light *asd)
{
	printf("----------LIGHT----------\n");
	printf("COORDINATES\n");
	printf("%f\t %f\t %f\n", asd->cordnts.x, asd->cordnts.y, asd->cordnts.z);
	printf("BRIGHTNESS\n");
	printf("%f\n", asd->brightness);
	printf("COLOR\n");
	printf("%d\t %d\t %d\n", asd->color.red, asd->color.green, asd->color.blue);
	printf("------------------------\n");
}

void	print_plane(t_plane *asd)
{
	printf("----------PLANE----------\n");
	printf("COORDINATES\n");
	printf("%f\t %f\t %f\n", asd->cordnts.x, asd->cordnts.y, asd->cordnts.z);
	printf("NORMAL\n");
	printf("%f\t %f\t %f\n", asd->normal.x, asd->normal.y, asd->normal.z);
	printf("COLOR\n");
	printf("%d\t %d\t %d\n", asd->color.red, asd->color.green, asd->color.blue);
	printf("------------------------\n");
}

void	print_sphere(t_sphere *asd)
{
	printf("---------SPHERE---------\n");
	printf("COORDINATES\n");
	printf("%f , %f , %f\n", asd->cordnts.x, asd->cordnts.y, asd->cordnts.z);
	printf("DIAMETER\n");
	printf("%f\n", asd->diameter);
	printf("COLOR\n");
	printf("%d , %d , %d\n", asd->color.red, asd->color.green, asd->color.blue);
	printf("------------------------\n");
}
