/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:42:17 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/04 18:10:07 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pf_int(long long a, int *e)
{
	int				b;
	long long		c;
	char			d;

	b = ft_pf_intlen(a);
	if (a < 0)
	{
		ft_pf_putchar('-', e);
		a = -a;
		b--;
	}
	c = ft_pow(b);
	while (--b >= 0)
	{
		d = ((a / c) % 10) + 48;
		c /= 10;
		ft_pf_putchar(d, e);
	}
}
