/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:41:10 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/25 16:59:13 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <stdio.h>

void	temp_free(t_all **all, char **words, char **digits)
{
	free_words(digits);
	free_words(words);
	print_error(all, 0);
}

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
	return (1);
}

void	free_words(char **a)
{
	int	i;

	if (!a || !a[0])
		return ;
	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

char	**trim_words(t_all **all, char **a, int *count)
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
	words = (char **)malloc(sizeof(char *) * (c + 1));
	if (!words)
		print_error(all, 4);
	while (i < c)
	{
		words[i] = ft_strtrim(a[i], " \n\t\r\v\f");
		i++;
	}
	i = 0;
	while (i < c)
		free(a[i++]);
	free(a);
	words[i] = NULL;
	*count = c;
	return (words);
}
