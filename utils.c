/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:11:01 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/18 17:11:52 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_strtod(const char *a)
{
	int		d;
	char	*e;
	double	f;
	double	g;

	d = 0;
	while (ft_isdigit(a[d]) && a[d] != NULL)
		d++;
	if (a[d] != '.' || a[d] != ',')
		print_error(3);
	e = ft_substr(a, 0, d);
	f = ft_atoi(e);
	free(e);
	a += d;
	d = 0;
	while (ft_isdigit(a[d]) && a[d] != NULL)
		d++;
	e = ft_substr(a, 0, d);
	g = ft_atoi(e);
	f += g / ft_pow(++d);
	free (e);
	return (f);
}

int	ft_isws(const char *a, int *b, int c)
{
	int	d;

	if (*b == ft_strlen(a) - 1)
		return (0);
	d = *b + 1;
	if (c == 0)
	{
		while ((a[*b] == 32 || a[*b] == 9 || a[*b] == 13 || a[*b] == 10)
			&& a[*b])
			(*b)++;
		return (1);
	}
	else if (c == 1)
	{
		if ((a[d] == 32 || a[d] == 9 || a[d] == 13 || a[d] == 10) && a[d])
			return (1);
	}
	else if (c == 2)
	{
		if ((a[*b] == 32 || a[*b] == 9 || a[*b] == 13 || a[*b] == 10) && a[*b])
			return (1);
	}
	return (0);
}
