/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:08:01 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/18 13:11:00 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isws(const char *a, int *b, int c)
{
	int	d;

	if (*b == ft_strlen(a) - 1)
		return (0);
	d = *b + 1;
	if (c == 0)
	{
		while ((a[*b] == 32 || a[*b] == 9 || a[*b] == 13 || a[*b] == 10) && a[*b])
			(*b)++;
		return (1);
	}
	if (c == 1)
	{
		if ((a[d] == 32 || a[d] == 9 || a[d] == 13 || a[d] == 10) && a[d])
			return (1);
		else
			return (0);
	}
	if (c == 2)
	{
		if ((a[*b] == 32 || a[*b] == 9 || a[*b] == 13 || a[*b] == 10) && a[*b])
			return (1);
		return (0);
	}
	return (0);
}

void	check_camera(const char *a)
{
	int		b;
	int		c;
	char	*d;

	c = 0;
	b = 0;
	ft_isws(a, &b, 0);
	b++;
	ft_isws(a, &b, 0);
	c = b;
	while (!ft_isws(a, &c, 3))
		c++;
	c -= b;
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
