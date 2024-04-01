/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:18:04 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/01 08:32:04 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "keycode.h"
# include <math.h>
# include <stdbool.h>

# define WIDTH 1000
# define HEIGHT 1000

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

# define REFLECT 1000
# define PI 3.141592653589793238462643383279502984

typedef struct s_v3
{
	double	x;
	double	y;
	double	z;
}	t_v3;

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_color;

typedef struct s_hit
{
	double	hitNum;
	t_v3	hitPoint;
	t_v3	normal;
	int		color;
	int		type;
	void	*object;
}	t_hit;

typedef struct s_ray
{
	t_v3	origin;
	t_v3	direction;
	t_hit	hit;
}	t_ray;

typedef struct s_ambient
{
	double		l_ratio;
	t_color		color;
}	t_ambient;

typedef struct s_cam_prop
{
	t_v3	horizontal;
	t_v3	vertical;
	t_v3	left_bottom;
	t_v3	w;
	t_v3	u;
	t_v3	v;
}	t_cam_prop;

typedef struct s_camera
{
	t_v3		cordnts;
	t_v3		normal;
	double		fov;
	t_cam_prop	props;
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
int		destroy_exit(t_all **all);
int		key_press(int keycode, t_all **all);
void	create_everything(t_all **all);
void	key_hooks(t_all **all);
// INTERSECTION CHECK FUNCTIONS
bool	check_intersection(t_all **all, t_ray *tmp);
void	sphere_intersect(t_all **all, t_ray *vector, bool *a);
// VECTOR CALCULATION FUNCTIONS
double	dot_v3(t_v3 a, t_v3 b);
t_v3	subtract_v3(t_v3 a, t_v3 b);
t_v3	add_v3(t_v3 a, t_v3 b);
t_v3	divide_v3(t_v3 a, double b);
t_v3	scale_v3(t_v3 a, double b);
t_v3	add_num_v3(t_v3 a, double b);
t_v3	subtract_num_v3(t_v3 a, double b);
t_v3	cross_v3(const t_v3 vec1, const t_v3 vec2);
t_v3	normalize(t_v3 vec);
t_v3	create_vector(double x, double y, double z);
double	len_v3(t_v3 v);
double	max(double a, double b);
double	min(double a, double b);
// COLOR FUNCS
void	set_color(t_all **all, int x, int y, t_color color);
int		clamp(int x);
int		colorToInt(t_color v3_color);
t_color	intToColor(int color);
int		add_color(int color_a, int color_b);
int		scale_color(int color, float c);
int		color_product(int color_a, int color_b);
int		color_comp(t_light light, t_hit hit);

#endif