#include "figures/figures.h"

/**
 * Calculates the intersection distance t for a ray and cylinder.
 *
 * @param ray Ray structure (origin and direction).
 * @param cyl Pointer to the cylinder structure.
 *
 * @return    Intersection distance t (>0 if hit, -1 otherwise).
 */
double	hit_cylinder(t_ray ray, t_cylinder *cyl)
{
	double	t_body;
	double	t_caps;

	t_body = hit_cylinder_body(ray, cyl);
	t_caps = hit_cylinder_caps(ray, cyl);
	return (min_pos_value(t_body, t_caps));
}
