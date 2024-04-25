/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:42:02 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/04 18:10:19 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pf_pointer(void *a, int *b)
{
	unsigned long long int	c;

	c = (unsigned long long int)a;
	ft_pf_string("0x", b);
	ft_pf_hex(c, 1, b);
}
