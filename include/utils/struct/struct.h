#ifndef STRUCT_H
# define STRUCT_H

#include "main.h"

void	copy_color(t_color *dest, const t_color *src);
void	copy_vec(t_vec *dest, const t_vec *src);
void	copy_amb_light(t_amb_light *dest, const t_amb_light *src);
void	copy_camera(t_camera *dest, const t_camera *src);
void	copy_light(t_light *dest, const t_light *src);
void	copy_sphere(t_sphere *dest, const t_sphere *src);
void	copy_plane(t_plane *dest, const t_plane *src);
void	copy_cylinder(t_cylinder *dest, const t_cylinder *src);
void	copy_scene(t_scene *dest, const t_scene *src);

#endif