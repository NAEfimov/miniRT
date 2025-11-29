#include "../include/figures/figures.h"

/**
 * Checks if a ray intersects a plane.
 *
 * @param ray   Ray structure (origin and direction).
 * @param plane Pointer to the plane structure.
 *
 * @return      1 if the ray intersects the plane, 0 otherwise.
 *
 */
int hit_plane(t_ray ray, t_plane *plane)
{
	double	denom;
	double	t;
	t_vec	diff;

	denom = vec_dot(plane->normal, ray.direction);
	if (fabs(denom) < 1e-6)
		return 0;
	diff = vec_sub(plane->coord, ray.origin);
	t = vec_dot(diff, plane->normal) / denom;
	if (t > 0)
		return 1;
	return 0;
}