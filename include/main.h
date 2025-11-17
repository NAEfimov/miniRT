#ifndef MAIN_H
# define MAIN_H

#include <stdint.h>

#define WIDTH		256
#define HEIGHT		256
#define COLOR_NUM	3

typedef struct s_color 
{
	uint8_t	r;
	uint8_t	g;
	uint8_t b;
} t_color;

typedef struct	s_vec
{
	double x;
	double y;
	double z;
}	t_vec;

typedef struct	s_amb_light
{
	double	ratio;
	t_color	color;
}	t_amb_light;

typedef struct	s_camera
{
	t_vec		coord;
	t_vec		orient;
	uint32_t	fov;
}	t_camera;

typedef struct	s_light
{
	t_vec	coord;
	double	brigh;
	t_color	color;
}	t_light;

typedef struct	s_sphere
{
	t_vec	coord;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct	s_plane
{
	t_vec	coord;
	t_vec	normal;
	t_color	color;
}	t_plane;

typedef struct	s_cylinder
{
	t_vec	coord;
	t_vec	normal;
	double	diameter;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct	s_scene
{
	uint32_t	width;
	uint32_t	height;
	uint32_t	*image;
	t_camera	*camera;
	t_amb_light	*a_light;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;
	int			sphere_num;
	int			plane_num;
	int			cyl_num;
}	t_scene;

int	read_scene(t_scene *scene, char *fname);
int	trace_scene(t_scene *scene);
int	draw_scene(t_scene *scene);
int	clean_scene(t_scene *scene);

// Check_arguments
int	check_args(int argc, char *argv[]);

#endif