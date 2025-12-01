#ifndef PRINT_H
# define PRINT_H

# include "main.h"

void	print_scene(t_scene *scene);

void	print_ambient_light(t_amb_light *a_light);
void	print_camera(t_camera *camera);
void	print_light(t_light *light);
void	print_sphere(t_sphere *sphere);
void	print_plane(t_plane *plane);
void	print_cylinder(t_cylinder *cyl);

void	print_rgb_color(t_rgb_color color);
void	print_color(t_vec *color);
void	print_vec(t_vec *vec, char *msg);
void	print_double(double value, char *msg);
void	print_uint32(uint32_t value, char *msg);

#endif
