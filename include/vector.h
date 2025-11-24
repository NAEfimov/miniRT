#include "main.h"

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

t_vec	vec_add(t_vec a, t_vec b);
t_vec	vec_scl(t_vec a, double s);
t_vec	vec_nrm(t_vec v);
t_vec	vec_crs(t_vec a, t_vec b);
