#ifndef PARSE_H
# define PARSE_H

# define VEC_DELIMETER ','

# include "main.h"

void	parse_line(t_scene *scene, char *line);
void	parse_scene_element(t_scene *scene, char **words);
void	parse_ambient_light(t_scene *scene, char **words);
void	parse_camera(t_scene *scene, char **words);
void	parse_light(t_scene *scene, char **words);
void	parse_sphere(t_scene *scene, char **words);
void	parse_plane(t_scene *scene, char **words);
void	parse_cylinder(t_scene *scene, char **words);

void	syntax_err(t_scene *scene, char **words);
void	malloc_err(t_scene *scene, char **words);
int		words_size(char **words);

#endif