/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:08:01 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/17 13:27:50 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	check_objects(t_all **all, const char *a)
{
	int		count;
	char	**words;

	count = 0;
	words = trim_words(all, ft_split(a, ' '), &count);
	if (!words || !words[0])
		print_error(all, 4);
	if (count >= 3)
	{
		if (ft_strcmp(words[0], "C") == 0)
			set_camera(all, words, count);
		else if (ft_strcmp(words[0], "A") == 0)
			set_ambient(all, words, count);
		else if (ft_strcmp(words[0], "L") == 0)
			set_light(all, words, count);
		else if (ft_strcmp(words[0], "sp") == 0)
			set_sphere(all, words, count);
		else if (ft_strcmp(words[0], "pl") == 0)
			set_plane(all, words, count);
		else if (ft_strcmp(words[0], "cy") == 0)
			set_cylinder(all, words, count);
	}
	free_words(words);
}

void	take_inputs(t_all **all, int argc, char **argv)
{
	char	*a;
	int		fd;

	if (argc != 2)
		print_error(all, 0);
	a = ft_strrchr(argv[1], '.');
	if (a == NULL || *(a + 1) != 'r' || *(a + 2) != 't')
		print_error(all, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(all, 1);
	while (1)
	{
		a = ft_gnl(fd);
		if (!a)
			break ;
		if (ft_strlen(a) > 9)
			check_objects(all, a);
		free(a);
	}
	if (!(*all)->world->camera || !(*all)->world->ambient \
			|| !(*all)->world->light)
		print_error(all, 5);
	close(fd);
}
