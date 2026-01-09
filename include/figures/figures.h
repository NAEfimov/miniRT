#ifndef FIGURES_H
# define FIGURES_H

# include "main.h"
# include "vector/vector.h"
# include "trace/trace.h"

double	hit_plane(t_ray ray, t_plane *plane);
double	hit_sphere(t_ray ray, t_sphere *sphere);

#endif