/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:41:10 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/09 14:30:32 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <stdio.h>

void	key_hooks(t_all **all)
{
	mlx_hook((*all)->mlx->window, CROSS, 1, destroy_exit, all);
	mlx_hook((*all)->mlx->window, 2, 1, key_press, all);
	mlx_loop((*all)->mlx->ptr);
}

int	key_press2(int keycode, t_all **all)
{
	if (keycode == RIGHT_ARROW)
	{
		printf("RIGHT \n");
		(*all)->world->camera->cordnts.x += 0.5;
		create_everything(all);
	}
}

void	free_words(char **a)
{
	int	i;

	if (!a)
		return ;
	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

char	**trim_words(t_all **all, char **a)
{
	char	**words;
	int		i;
	int		c;

	if (!a)
		return (NULL);
	i = 0;
	c = 0;
	while (a[c])
		c++;
	words = (char **)malloc(sizeof(char *) * (c));
	if (!words)
		print_error(all, 4);
	while (i < c)
	{
		words[i] = ft_strtrim(a[i], " \n\t\r\v\f");
		printf("%s\n", words[i]);
		i++;
	}
	i = 0;
	while (i < c)
	{
		free(a[i]);
		i++;
	}
	free(a);
	words[i] = NULL;
	return (words);
}
