#include "../include/figures/figures.h"

/**
 * Calculates the intersection distance t for a ray and plane.
 *
 * @param ray   Ray structure (origin and direction).
 * @param plane Pointer to the plane structure.
 *
 * @return      Intersection distance t (>0 if hit, -1 otherwise).
 */
double	hit_plane(t_ray ray, t_plane *plane)
{
	double	denom;
	t_vec	diff;
	double	t;

	denom = vec_dot(plane->normal, ray.direction);
	if (fabs(denom) < 1e-6)
		return (-1.0);
	diff = vec_sub(plane->coord, ray.origin);
	t = vec_dot(diff, plane->normal) / denom;
	if (t > 0)
		return (t);
	return (-1.0);
}
