#ifndef MAIN_H
# define MAIN_H

# include <math.h>
# include <stdint.h>
# include "libft.h"

# define WIDTH		512
# define HEIGHT		512
# define COLOR_NUM	3
# define BG_COLOR	0x00000000
# define AA_SAMPLES	4
# define SHINE		50

typedef struct s_rgb_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb_color;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_amb_light
{
	double	ratio;
	t_vec	color;
}	t_amb_light;

typedef struct s_camera
{
	t_vec		coord;
	t_vec		orient;
	uint32_t	fov;
}	t_camera;

typedef struct s_light
{
	t_vec	coord;
	double	brigh;
	t_vec	color;
}	t_light;

typedef struct s_sphere
{
	t_vec	coord;
	double	diameter;
	t_vec	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec	coord;
	t_vec	normal;
	t_vec	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	coord;
	t_vec	normal;
	double	diameter;
	double	height;
	t_vec	color;
}	t_cylinder;

typedef struct s_hit_point
{
	double	min_t;
	t_vec	point;
	t_vec	normal;
	t_vec	obj_color;
}	t_hit_point;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_scene
{
	uint32_t	width;
	uint32_t	height;
	uint32_t	*image;
	t_camera	*camera;
	t_amb_light	*a_light;
	t_light		*light;
	t_list		*sphere;
	t_list		*plane;
	t_list		*cyl;
	char		*line;
	t_mlx_data	mlx;
}	t_scene;

void	check_args(int argc, char **argv);
int		clean_scene(t_scene *scene);
void	clean_words(char **words);
int		draw_scene(t_scene *scene);
int		read_scene(t_scene *scene, char *fname);
int		trace_scene(t_scene *scene);

#endif