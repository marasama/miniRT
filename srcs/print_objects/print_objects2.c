/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:05:26 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/01 09:28:42 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <stdio.h>

void	print_cylinder(t_cylinder *asd)
{
	t_color	rgb;

	rgb = int_to_color(asd->color);
	printf("--------CYLINDER--------\n");
	printf("COORDINATES\n");
	printf("%f\t %f\t %f\n", asd->cordnts.x, asd->cordnts.y, asd->cordnts.z);
	printf("NORMAL\n");
	printf("%f\t %f\t %f\n", asd->normal.x, asd->normal.y, asd->normal.z);
	printf("DIAMETER\n");
	printf("%f\n", asd->diameter);
	printf("HEIGHT\n");
	printf("%f\n", asd->height);
	printf("COLOR\n");
	printf("%d\t %d\t %d\n", rgb.red, rgb.green, rgb.blue);
	printf("------------------------\n");
}
