#include "figures/figures.h"
#include <math.h>

/**
 * Calculates quadratic coefficients for infinite cylinder-ray intersection.
 *
 * @param ray Ray structure (origin and direction)
 * @param cyl Pointer to the cylinder structure
 * @param oc  Vector from cylinder axis point to ray origin
 * @param abc Array to store coefficients [a, b, c]
 */
static void	get_cyl_coeffs(t_ray ray, t_cylinder *cyl, t_vec oc, double abc[3])
{
	t_vec	dir_proj;
	t_vec	oc_proj;
	double	radius;
	double	scalar_proj;

	radius = cyl->diameter * 0.5;
	scalar_proj = vec_dot(ray.direction, cyl->normal);
	dir_proj = vec_sub(ray.direction, vec_scl(cyl->normal, scalar_proj));
	oc_proj = vec_sub(oc, vec_scl(cyl->normal, vec_dot(oc, cyl->normal)));
	abc[0] = vec_dot(dir_proj, dir_proj);
	abc[1] = 2.0 * vec_dot(oc_proj, dir_proj);
	abc[2] = vec_dot(oc_proj, oc_proj) - radius * radius;
}

/**
 * Checks if a point at parameter t is within cylinder height bounds.
 *
 * @param ray Ray structure
 * @param cyl Cylinder structure
 * @param t   Parameter value along the ray
 *
 * @return 1 if within bounds, 0 otherwise
 */
static int	is_within_cylinder_height(t_ray ray, t_cylinder *cyl, double t)
{
	t_vec	hit_point;
	t_vec	to_hit;
	double	proj;

	hit_point = vec_add(ray.origin, vec_scl(ray.direction, t));
	to_hit = vec_sub(hit_point, cyl->coord);
	proj = vec_dot(to_hit, cyl->normal);
	return (proj >= -cyl->height * 0.5 && proj <= cyl->height * 0.5);
}

/**
 * Tests intersection with cylinder body.
 *
 * @param ray Ray structure
 * @param cyl Cylinder structure
 *
 * @return Distance t to nearest body intersection, or -1 if no hit
 */
double	hit_cylinder_body(t_ray ray, t_cylinder *cyl)
{
	double	abc[3];
	double	discrim;
	t_vec	oc;
	double	t1;
	double	t2;

	oc = vec_sub(ray.origin, cyl->coord);
	get_cyl_coeffs(ray, cyl, oc, abc);
	discrim = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discrim >= 0 && fabs(abc[0]) > 1e-6)
	{
		discrim = sqrt(discrim);
		t1 = (-abc[1] - discrim) / (2.0 * abc[0]);
		t2 = (-abc[1] + discrim) / (2.0 * abc[0]);
		if (t1 > 0 && is_within_cylinder_height(ray, cyl, t1))
			return (t1);
		else if (t2 > 0 && is_within_cylinder_height(ray, cyl, t2))
			return (t2);
	}
	return (-1);
}
