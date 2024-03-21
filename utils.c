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
#include <fcntl.h>
#include <stdio.h>

double	ft_strtod(t_all **all, const char *a)
{
	int		d;
	char	*e;
	double	f;
	double	g;

	d = 0;
	while (ft_isdigit(a[d]) && a[d] != NULL)
		d++;
	if (a[d] != '.' || a[d] != ',')
		print_error(all, 3);
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

void	free_everything(t_all **all)
{
	if (!(*all)->mallocs)
	{
		free((*all));
		return;
	}
	if ((*all)->mallocs->next != NULL)
		free_everything(&(*all)->mallocs->next);
	if ((*all)->mallocs->content)
		(*all)->mallocs->content = (free((*all)->mallocs->content), NULL);
	if ((*all)->mallocs)
		(*all)->mallocs = (free((*all)->mallocs), NULL);
}

void	print_error(t_all **all, int opt)
{
	printf("\e[33mError\e[0m\n");
	if (opt == 0)
		printf("\e[35mWrong argument input!!!\e[0m\n");
	else if (opt == 1)
		printf("\e[35mFile opening error...\e[0m\n");
	else if (opt == 2)
		printf("\e[35mFile instructions are not satisfying!!\e[0m");
	else if (opt == 3)
		printf("\e[35mNumber is not in the allowed range!!\e[0m");
	else if (opt == 4)
		printf("\e[35mMemory allocation error!!\e[0m");
	free_everything(all);
	exit(1);
}

void	check_args(t_all **all, int argc, char **argv)
{
	char	*a;
	int		b;
	int		fd;

	if (argc != 2)
		print_error(all, 0);
	a = ft_strrchr(argv[1], '.');
	b = 0;
	if (*(a + 1) != 'r' || *(a + 2) != 't' || a == 0)
		print_error(all, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(all, 1);
	while (a != NULL)
	{
		a = ft_gnl(fd);
		check_objects(a, &b);
		free(a);
		b++;
	}
	close(fd);
	if (b < 3)
		print_error(all, 2);
}