/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:08:01 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/18 17:39:43 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_camera(const char *a)
{
	int		b;
	int		c;
	double	e;

	e = 0;
	c = 0;
	b = 0;
	ft_isws(a, &b, 0);
	b++;
	ft_isws(a, &b, 0);
	c = b;
	while (!ft_isws(a, &c, 3))
		c++;
	c -= b;
	e = 0;
}

void	check_objects(const char *a, int *b)
{
	int		c;

	c = 0;
	ft_isws(a, &c, 0);
	if (a[c] == 'C' && ft_isws(a, &c, 1))
		check_camera(a);
	else if (a[c] == 'A' && ft_isws(a, &c, 1))
		check_ambient(a);
}
