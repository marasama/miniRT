/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:11:01 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/17 19:59:38 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

double	ft_strtod(const char *a)
{
	int		d;
	double	f;
	double	g;

	d = 0;
	f = ft_atoi(a);
	while (a[d] == '-' || a[d] == '+')
		d++;
	while (ft_isdigit(a[d]) && a[d])
		d++;
	if (a[d] != '.' || !a[d] || !ft_isdigit(a[d + 1]))
		return (f);
	d++;
	a += d;
	d = 0;
	g = ft_atoi(a);
	while (ft_isdigit(a[d]) && a[d])
		d++;
	if (f >= 0)
		f += (g / ft_pow(++d));
	else
		f -= (g / ft_pow(++d));
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

void	free_list(t_list **mem)
{
	t_list	*tmp;

	if (mem == NULL || *mem == NULL)
		return ;
	while ((*mem) != NULL)
	{
		tmp = (*mem);
		(*mem) = (*mem)->next;
		free (tmp->content);
		free (tmp);
	}
}

void	print_error(t_all **all, int opt)
{
	printf("\e[33mError\e[0m\n");
	if (opt == 0)
		printf("\e[35mWrong argument input!!!\e[0m\n");
	else if (opt == 1)
		printf("\e[35mFile opening error...\e[0m\n");
	else if (opt == 2)
		printf("\e[35mFile instructions are not satisfying!!\e[0m\n");
	else if (opt == 3)
		printf("\e[35mNumber is not in the allowed range!!\e[0m\n");
	else if (opt == 4)
		printf("\e[35mMemory allocation error!!\e[0m\n");
	else if (opt == 5)
	{
		printf("\e[35mYou can only have one camera, \
			ambient and light object!!\e[0m\n");
	}
	destroy_exit(0, all);
	exit(1);
}
