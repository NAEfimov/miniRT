#ifndef NORMAL_H
# define NORMAL_H

#include "main.h"

t_vec sphere_normal(t_vec point, t_sphere *sphere);
t_vec cylinder_normal(t_vec point, t_cylinder *cyl);
t_vec normal_to_color(t_vec normal);
t_vec sphere_normal_color(t_vec point, t_sphere *sphere);

#endif