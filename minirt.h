/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:18:04 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/18 17:44:37 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <math.h>

# define WIDTH 600
# define HEIGHT 600
# define AMBIENT 1
# define CAMERA 2
# define LIGHT 3
# define SPHERE 4
# define PLANE 5
# define CYLINDER 6

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_color;

typedef struct s_ambient
{
	t_vector	coordinates;
	double		l_ratio;
	t_color		color;
}	t_ambient;

typedef struct s_camera
{
	t_vector	coordinates;
	t_vector	orientation;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_vector	coordinates;
	double		brightness;
	t_color		color;
}	t_light;

typedef struct s_sphere
{
	t_vector	coordinates;
	double		diameter;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	coordinates;
	t_vector	normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	coordinates;
	t_vector	axis;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	void			*image;
	unsigned char	*pixels;
	int				bpp;
	int				endian;
	int				size_line;
}	t_mlx;

typedef struct s_world
{
	t_camera	*camera;
	t_ambient	*ambient;
	t_light		*light;
	t_list		*planes;
	t_list		*cylinders;
	t_list		*spheres;
}	t_world;

typedef struct s_all
{
	t_mlx	*mlx;
	t_world	*world;
	t_list	*mallocs;
}	t_all;

void	print_error(t_all **all, int opt);
int		ft_isws(const char *a, int *b, int c);
double	ft_strtod(t_all **all, const char *a);
void	free_everything(t_all **all);
void	print_error(t_all **all, int opt);
void	check_args(t_all **all, int argc, char **argv);

#endif