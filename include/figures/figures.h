#ifndef FIGURES_H
# define FIGURES_H

# include "main.h"
# include "vector/vector.h"
# include "trace/trace.h"

double	hit_plane(t_ray ray, t_plane *plane);

double	hit_sphere(t_ray ray, t_sphere *sphere);
double	min_pos_value(double a, double b);

double	hit_cylinder(t_ray ray, t_cylinder *cyl);
double	hit_cylinder_caps(t_ray ray, t_cylinder *cyl);
double	hit_cylinder_body(t_ray ray, t_cylinder *cyl);

#endif