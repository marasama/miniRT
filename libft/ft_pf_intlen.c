/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_intlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:42:06 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/04 18:10:15 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_intlen(long long a)
{
	int	b;

	b = 0;
	if (a < 0)
	{
		a = -a;
		b++;
	}
	while ((a / 10) != 0)
	{
		a /= 10;
		b++;
	}
	return (b + 1);
}
