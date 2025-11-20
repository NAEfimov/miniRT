#ifndef READ_H
# define READ_H

# include "main.h"

int	read_int(int *num, char *word);
int	read_double(double *num, char *word);
int	read_color(t_scene *scene, t_color *color, char *word);
int	read_normal(t_scene *scene, t_vec *norm, char *word);
int	read_vec(t_scene *scene, t_vec *vec, char *word);

#endif