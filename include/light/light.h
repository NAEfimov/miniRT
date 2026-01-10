#ifndef LIGHT_H
# define LIGHT_H

# include "main.h"
# include "trace/trace.h"

typedef struct s_phong_light
{
    t_vec	l_dir;
	double	l_dist;
	t_ray	sh_ray;
	double	eps;
    double  attenuation;
    double  dot_nl;
    double  dot_rv;

}   t_phong_light;

void	calc_ambient_light(t_scene *scene, t_vec *final_color, t_hit_point *hit);
void	calc_phong_lightning(t_scene *scene, t_vec *final_color, t_hit_point *hit, t_ray *ray);


#endif