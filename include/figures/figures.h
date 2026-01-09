#ifndef FIGURES_H
# define FIGURES_H

# include "main.h"
# include "vector/vector.h"
# include "trace/trace.h"

int		hit_plane (t_ray ray, t_plane *plane);
double	hit_plane_t(t_ray ray, t_plane *plane);
double calc_discrim(t_ray *ray, t_sphere *sphere, double *a, double *b);
double	hit_sphere_t(t_ray ray, t_sphere *sphere);

#endif