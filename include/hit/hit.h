#ifndef HIT_H
# define HIT_H

# include "main.h"
# include "trace/trace.h"

int     hits_any_object(t_scene *scene, t_ray ray, double max_t);
void	min_sphere_t(t_list	*current, t_ray *ray, t_hit_point *hit);
void	min_plane_t(t_list	*current, t_ray *ray, t_hit_point *hit);
void	min_cylinder_t(t_list	*current, t_ray *ray, t_hit_point *hit);

#endif