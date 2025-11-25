#include "main.h"
#include <math.h>
typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_cam_basis
{
    t_vec forward;
    t_vec right;
    t_vec up;
} t_cam_basis;

typedef struct s_pixel_offset
{
    double px;
    double py;
} t_pixel_offset;

t_vec			vec_add(t_vec a, t_vec b);
t_vec			vec_scl(t_vec a, double s);
t_vec			vec_nrm(t_vec v);
t_vec			vec_crs(t_vec a, t_vec b);
t_vec  			vec_sub(t_vec a, t_vec b);
double 			vec_dot(t_vec a, t_vec b);
double			vec_sq_len(t_vec v);
double			vec_len(t_vec v);
t_cam_basis		get_cam_basis(t_camera *cam);
t_pixel_offset	get_pixel_offset(t_scene *scene, int x, int y);
t_ray			generate_ray(t_scene *scene, int x, int y);
