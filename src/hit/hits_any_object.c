#include "hit/hit.h"
#include "figures/figures.h"

/**
 * Checks if the given ray intersects any sphere in the list within the
 * specified maximum distance.
 * 
 * @param ray The ray to test for intersections.
 * @param max_t The maximum distance to check for intersections.
 * @param current Pointer to the list of spheres.
 * 
 * @return 1 if the ray hits any sphere, 0 otherwise.
 */
int	hits_any_sphere(t_ray ray, double max_t, t_list *current)
{
	t_sphere	*sph;
	double		t;

	while (current)
	{
		sph = (t_sphere *)current->content;
		t = hit_sphere(ray, sph);
		if (t > 0.001 && t < max_t)
			return (1);
		current = current->next;
	}
	return (0);
}

/**
 * Checks if the given ray intersects any plane in the list within the
 * specified maximum distance.
 * 
 * @param ray The ray to test for intersections.
 * @param max_t The maximum distance to check for intersections.
 * @param current Pointer to the list of planes.
 * 
 * @return 1 if the ray hits any plane, 0 otherwise.
 */
int	hits_any_plane(t_ray ray, double max_t, t_list *current)
{
	t_plane	*pln;
	double	t;

	while (current)
	{
		pln = (t_plane *)current->content;
		t = hit_plane(ray, pln);
		if (t > 0.001 && t < max_t)
			return (1);
		current = current->next;
	}
	return (0);
}

/**
 * Checks if the given ray intersects any cylinder in the list within
 * the specified maximum distance.
 * 
 * @param ray The ray to test for intersections.
 * @param max_t The maximum distance to check for intersections.
 * @param current Pointer to the list of cylinders.
 * 
 * @return 1 if the ray hits any cylinder, 0 otherwise.
 */
int	hits_any_cylinder(t_ray ray, double max_t, t_list *current)
{
	t_cylinder	*cyl;
	double		t;

	while (current)
	{
		cyl = (t_cylinder *)current->content;
		t = hit_cylinder(ray, cyl);
		if (t > 0.001 && t < max_t)
			return (1);
		current = current->next;
	}
	return (0);
}

/**
 * Checks if the given ray intersects any object in the scene within the
 * specified maximum distance.
 * 
 * @param scene Pointer to the scene structure.
 * @param ray The ray to test for intersections.
 * @param max_t The maximum distance to check for intersections.
 * 
 * @return 1 if the ray hits any object, 0 otherwise.
 */
int	hits_any_object(t_scene *scene, t_ray ray, double max_t)
{
	if (hits_any_sphere(ray, max_t, scene->sphere))
		return (1);
	if (hits_any_plane(ray, max_t, scene->plane))
		return (1);
	if (hits_any_cylinder(ray, max_t, scene->cyl))
		return (1);
	return (0);
}
