#include "hit/hit.h"
#include "figures/figures.h"
#include "normal/normal.h"

/**
 * Finds the closest intersection with spheres and updates the hit point if
 * closer.
 * 
 * @param current Pointer to the list of spheres.
 * @param ray Pointer to the ray.
 * @param hit Pointer to the hit point structure to update.
 */
void	min_sphere_t(t_list	*current, t_ray *ray, t_hit_point *hit)
{
	double		t;
	t_sphere	*sph;
	t_vec		oc;

	while (current)
	{
		sph = (t_sphere *)current->content;
		t = hit_sphere(*ray, sph);
		if (t > 0 && t < hit->min_t)
		{
			hit->min_t = t;
			hit->point = vec_add(ray->origin, vec_scl(ray->direction, t));
			hit->normal = sphere_normal(hit->point, sph);
			// Flip normal if we're hitting from inside the sphere
			oc = vec_sub(ray->origin, sph->coord);
			if (vec_dot(oc, oc) < (sph->diameter * 0.5 * sph->diameter * 0.5))
				hit->normal = vec_scl(hit->normal, -1.0);
			hit->obj_color = sph->color;
		}
		current = current->next;
	}
}

/**
 * Finds the closest intersection with planes and updates the hit point if
 * closer.
 * 
 * @param current Pointer to the list of planes.
 * @param ray Pointer to the ray.
 * @param hit Pointer to the hit point structure to update.
 */
void	min_plane_t(t_list	*current, t_ray *ray, t_hit_point *hit)
{
	double		t;
	t_plane		*pln;

	while (current)
	{
		pln = (t_plane *)current->content;
		t = hit_plane(*ray, pln);
		if (t > 0 && t < hit->min_t)
		{
			hit->min_t = t;
			hit->point = vec_add(ray->origin, vec_scl(ray->direction, t));
			hit->normal = pln->normal;
			// Flip normal if it points away from the ray (two-sided plane)
			if (vec_dot(hit->normal, ray->direction) > 0)
				hit->normal = vec_scl(hit->normal, -1.0);
			hit->obj_color = pln->color;
		}
		current = current->next;
	}
}

/**
 * Finds the closest intersection with cylinders and updates the hit point if
 * closer.
 * 
 * @param current Pointer to the list of cylinders.
 * @param ray Pointer to the ray.
 * @param hit Pointer to the hit point structure to update.
 */
void	min_cylinder_t(t_list	*current, t_ray *ray, t_hit_point *hit)
{
	double		t;
	t_cylinder	*cyl;

	while (current)
	{
		cyl = (t_cylinder *)current->content;
		t = hit_cylinder(*ray, cyl);
		if (t > 0 && t < hit->min_t)
		{
			hit->min_t = t;
			hit->point = vec_add(ray->origin, vec_scl(ray->direction, t));
			hit->normal = cylinder_normal(hit->point, cyl);
			if (vec_dot(hit->normal, ray->direction) > 0)
				hit->normal = vec_scl(hit->normal, -1.0);
			hit->obj_color = cyl->color;
		}
		current = current->next;
	}
}
