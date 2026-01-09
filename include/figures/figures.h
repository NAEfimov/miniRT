#ifndef FIGURES_H
# define FIGURES_H

# include "main.h"
# include "vector/vector.h"
# include "trace/trace.h"

int		hit_plane (t_ray ray, t_plane *plane);
double	hit_plane_t(t_ray ray, t_plane *plane);
int		hit_sphere(t_ray ray, t_sphere *sphere);
double	hit_sphere_t(t_ray ray, t_sphere *sphere);

#endif