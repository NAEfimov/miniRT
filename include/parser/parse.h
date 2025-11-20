#ifndef PARSE_H
# define PARSE_H

# include "main.h"

void	parse_line(t_scene *scene, char *line);
void	parse_scene_element(t_scene *scene, char **words);
void	parse_ambient_light(t_scene *scene, char **words);
void	parse_camera(t_scene *scene, char **words);
void	parse_light(t_scene *scene, char **words);
void	parse_sphere(t_scene *scene, char **words);
void	parse_plane(t_scene *scene, char **words);
void	parse_cylinder(t_scene *scene, char **words);

#endif