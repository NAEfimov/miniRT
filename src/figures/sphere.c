#include "../include/figures/figures.h"

/**
 * Checks if a ray intersects a sphere.
 *
 * @param ray    Ray structure (origin and direction).
 * @param sphere Pointer to the sphere structure.
 *
 * @return       1 if the ray intersects the sphere, 0 otherwise.
 *
 */
int hit_sphere(t_ray ray, t_sphere *sphere)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discrim;

	oc = vec_sub(ray.origin, sphere->coord);
	a = vec_dot(ray.direction, ray.direction);
	b = 2.0 * vec_dot(oc, ray.direction);
	c = vec_dot(oc, oc) - sphere->diameter * 0.5 * sphere->diameter * 0.5;
	discrim = b * b - 4 * a * c;
	return (discrim >= 0);
}