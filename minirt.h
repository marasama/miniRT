/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:18:04 by adurusoy          #+#    #+#             */
/*   Updated: 2024/03/25 03:09:36 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <math.h>

# define WIDTH 600
# define HEIGHT 600

typedef struct s_v3
{
	double	x;
	double	y;
	double	z;
}	t_v3;

typedef struct s_vector
{
	t_v3	s_point;
	t_v3	d_point;
}	t_vector;

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_color;

typedef struct s_ambient
{
	double		l_ratio;
	t_color		color;
}	t_ambient;

typedef struct s_camera
{
	t_v3		cordnts;
	t_v3		normal;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_v3		cordnts;
	double		brightness;
	t_color		color;
}	t_light;

typedef struct s_sphere
{
	t_v3		cordnts;
	double		diameter;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_v3		cordnts;
	t_v3		normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_v3		cordnts;
	t_v3		normal;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

typedef struct s_mlx
{
	void			*ptr;
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
double	ft_strtod(const char *a);
void	free_everything(t_list **mem);
void	print_error(t_all **all, int opt);
void	check_args(t_all **all, int argc, char **argv);
void	check_objects(t_all **all, const char *a);
// SET OBJECTS FUNCTIONS
void	take_color(const char *a, t_color *rgb);
void	take_v3(const char *a, t_v3*v3);
void	set_camera(t_all **all, const char *a);
void	set_ambient(t_all **all, const char *a);
void	set_light(t_all **all, const char *a);
void	set_plane(t_all **all, const char *a);
void	set_sphere(t_all **all, const char *a);
void	set_cylinder(t_all **all, const char *a);
// PRINT OBJECTS FUNCTIONS
void	print_camera(t_camera *asd);
void	print_ambient(t_ambient *asd);
void	print_light(t_light *asd);
void	print_plane(t_plane *asd);
void	print_sphere(t_sphere *asd);
void	print_cylinder(t_cylinder *asd);
// IMAGE CREATION FUNCTIONS
void	create_everything(t_all **all);

#endif