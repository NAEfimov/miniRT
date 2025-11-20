#ifndef PARSE_H
# define PARSE_H

# include "main.h"

void	parse_scene_element(t_scene *scene, char **words);
int	parse_ambient_light(t_scene *scene, char **words);
int	parse_camera(t_scene *scene, char **words);
int	parse_light(t_scene *scene, char **words);
int	parse_sphere(t_scene *scene, char **words);
int	parse_plane(t_scene *scene, char **words);
int	parse_cylinder(t_scene *scene, char **words);

#endif