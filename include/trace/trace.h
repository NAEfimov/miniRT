#include "main.h"
#include "vector/vector.h"

typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_cam_basis
{
	t_vec	forward;
	t_vec	right;
	t_vec	up;
}	t_cam_basis;

typedef struct s_pixel_offset
{
	double	px;
	double	py;
}	t_pixel_offset;

t_ray	generate_ray(t_scene *scene, int x, int y);
