/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:05:26 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/25 01:17:11 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdio.h>

void	print_cylinder(t_cylinder *asd)
{
	printf("--------CYLINDER--------\n");
	printf("COORDINATES\n");
	printf("%f\t %f\t %f\n", asd->coordinates.x, asd->coordinates.y, asd->coordinates.z);
	printf("NORMAL\n");
	printf("%f\t %f\t %f\n", asd->axis.x, asd->axis.y, asd->axis.z);
    printf("DIAMETER\n");
	printf("%f\n", asd->diameter);
    printf("HEIGHT\n");
	printf("%f\n", asd->height);
	printf("COLOR\n");
	printf("%d\t %d\t %d\n", asd->color.red, asd->color.green, asd->color.blue);
	printf("------------------------\n");
}