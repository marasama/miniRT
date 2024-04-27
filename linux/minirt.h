/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:18:04 by adurusoy          #+#    #+#             */
/*   Updated: 2024/04/27 13:27:23 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdbool.h>

# define WIDTH 1000
# define HEIGHT 1000

# define CROSS 17
# define ESC 65307
# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363

# define PI 3.14
# define EPSILON 0.0001

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
	double	hit_len;
	t_v3	hit_point;
	t_v3	normal;
	int		color;
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
	int			color;
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
	int			color;
}	t_light;

typedef struct s_sphere
{
	t_v3		cordnts;
	double		diameter;
	int			color;
}	t_sphere;

typedef struct s_plane
{
	t_v3		cordnts;
	t_v3		normal;
	int			color;
}	t_plane;

typedef struct s_cylinder
{
	t_v3		cordnts;
	t_v3		normal;
	double		diameter;
	double		height;
	int			color;
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

// UTILS FUNCTIONS
void	free_words(char **a);
char	**trim_words(t_all **all, char **a, int *count);
void	print_error(t_all **all, int opt);
double	ft_strtod(const char *a);
void	free_list(t_list **mem);
void	print_error(t_all **all, int opt);
void	take_inputs(t_all **all, int argc, char **argv);
void	check_objects(t_all **all, char *a);
t_v3	check_nor(t_v3 *a);
// INPUT FUNCTIONS
void	temp_free(t_all **all, char **words, char **digits);
int		take_color(t_all **all, const char *a, char *b, char **words);
t_v3	take_v3(t_all **all, const char *a, char *b, char **words);
void	set_camera(t_all **all, char **words, int count, char *a);
void	set_ambient(t_all **all, char **words, int count, char *a);
void	set_light(t_all **all, char **words, int count, char *a);
void	set_plane(t_all **all, char **words, int count, char *a);
void	set_sphere(t_all **all, char **words, int count, char *a);
void	set_cylinder(t_all **all, char **words, int count, char *a);
// PRINT OBJECTS FUNCTIONS
void	print_camera(t_camera *asd);
void	print_ambient(t_ambient *asd);
void	print_light(t_light *asd);
void	print_plane(t_plane *asd);
void	print_sphere(t_sphere *asd);
void	print_cylinder(t_cylinder *asd);
// IMAGE CREATION FUNCTIONS
int		destroy_exit(t_all **all);
void	create_everything(t_all **all);
void	key_hooks(t_all **all);
int		key_press(int keycode, t_all **all);
int		key_press2(int keycode, t_all **all);
// INTERSECTION CHECK FUNCTIONS
bool	check_intersection(t_all **all, t_ray *tmp);
void	sphere_intersect(t_all **all, t_ray *ray, bool *a);
void	plane_intersect(t_all **all, t_ray *ray, bool *a);
void	cylinder_intersect(t_list *cy, t_ray *ray, bool *a);
// VECTOR CALCULATION FUNCTIONS
double	dot_v3(t_v3 a, t_v3 b);
t_v3	subtract_v3(t_v3 a, t_v3 b);
t_v3	add_v3(t_v3 a, t_v3 b);
t_v3	scale_v3(t_v3 a, double b);
t_v3	cross_v3(const t_v3 vec1, const t_v3 vec2);
t_v3	normalize(t_v3 vec);
t_v3	create_vector(double x, double y, double z);
double	len_v3(t_v3 v);
// COLOR FUNCS
void	set_color(t_all **all, int x, int y, t_color color);
int		clamp(int x, int max, int min);
int		color_to_int(t_color v3_color);
t_color	int_to_color(int color);
int		add_color(int color_a, int color_b);
int		scale_color(int color, float c);
int		color_product(int color_a, int color_b);
int		color_comp(t_light light, t_hit hit);
int		re_color(t_all **all, t_ray *ray);

#endif