/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:08:01 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/16 12:31:39 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <stdio.h>

void	check_objects(t_all **all, const char *a)
{
	int		count;
	char	**wrds;

	count = 0;
	wrds = trim_words(all, ft_split(a, ' '));
	if (!wrds || !wrds[0])
		print_error(all, 4);
	while (wrds[count])
		count++;
	if (count >= 3)
	{
		if (ft_strcmp(wrds[0], "C") == 0)
			set_camera(all, wrds, count);
		else if(ft_strcmp(wrds[0], "A") == 0)
			set_ambient(all, wrds, count);
		else if (ft_strcmp(wrds[0], "L") == 0)
			set_light(all, wrds, count);
		else if (ft_strlen(wrds[0]) == 2 && ft_strcmp(wrds[0], "sp") == 0)
			set_sphere(all, wrds, count);
		else if (ft_strlen(wrds[0]) == 2 && ft_strcmp(wrds[0], "pl") == 0)
			set_plane(all, wrds, count);
		else if (ft_strlen(wrds[0]) == 2 && ft_strcmp(wrds[0], "cy") == 0)
			set_cylinder(all, wrds, count);
	}
	free_words(wrds);
}
