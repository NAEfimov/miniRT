#include "figures/figures.h"

/**
 * Tests intersection with a cylinder cap (circle).
 *
 * @param ray Ray structure
 * @param cyl Cylinder structure
 *
 * @return Distance t to nearest cap intersection, or -1 if no hit
 */
static double	hit_cylinder_cap(t_ray ray, t_cylinder *cyl, t_vec cap_center,
					double denom)
{
	double	t;
	t_vec	diff;
	t_vec	to_hit;
	double	dist_sq;
	double	radius_sq;

	radius_sq = (cyl->diameter * 0.5) * (cyl->diameter * 0.5);
	diff = vec_sub(cap_center, ray.origin);
	t = vec_dot(diff, cyl->normal) / denom;
	if (t > 0)
	{
		to_hit = vec_sub(vec_add(ray.origin,
					vec_scl(ray.direction, t)), cap_center);
		dist_sq = vec_dot(to_hit, to_hit)
			- pow(vec_dot(to_hit, cyl->normal), 2);
		if (dist_sq <= radius_sq)
			return (t);
	}
	return (-1);
}

/**
 * Tests intersection with cylinder caps (top and bottom circles).
 *
 * @param ray Ray structure
 * @param cyl Cylinder structure
 *
 * @return Distance t to nearest cap intersection, or -1 if no hit
 */
double	hit_cylinder_caps(t_ray ray, t_cylinder *cyl)
{
	double	denom;
	t_vec	cap_ctr;
	double	t_bottom;
	double	t_top;

	t_bottom = -1;
	t_top = -1;
	denom = vec_dot(cyl->normal, ray.direction);
	if (fabs(denom) > 1e-6)
	{
		// Bottom cap
		cap_ctr = vec_sub(cyl->coord, vec_scl(cyl->normal, cyl->height * 0.5));
		t_bottom = hit_cylinder_cap(ray, cyl, cap_ctr, denom);
		// Top cap
		cap_ctr = vec_add(cyl->coord, vec_scl(cyl->normal, cyl->height * 0.5));
		t_top = hit_cylinder_cap(ray, cyl, cap_ctr, denom);
	}
	return (min_pos_value(t_bottom, t_top));
}
