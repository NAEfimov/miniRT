#include "../include/figures/figures.h"
#include <math.h>

/**
 * Calculates quadratic equation coefficients for sphere-ray intersection.
 *
 * @param ray    Ray structure (origin and direction)
 * @param sphere Pointer to the sphere structure
 * @param abc    Array to store coefficients [a, b, c]
 */
static void get_sphere_coeffs(t_ray ray, t_sphere *sphere, double abc[3])
{
	t_vec	oc;
	double	radius;

	oc = vec_sub(ray.origin, sphere->coord);
	radius = sphere->diameter * 0.5;
	abc[0] = vec_dot(ray.direction, ray.direction);
	abc[1] = 2.0 * vec_dot(oc, ray.direction);
	abc[2] = vec_dot(oc, oc) - radius * radius;
}

/**
 * Calculates the nearest positive t value from quadratic solution.
 *
 * @param a      Coefficient a
 * @param b      Coefficient b
 * @param discrim Square root of discriminant
 *
 * @return Nearest positive t, or -1 if no valid intersection
 */
static double get_nearest_t(double a, double b, double discrim)
{
	double t1;
	double t2;

	t1 = (-b - discrim) / (2.0 * a);
	t2 = (-b + discrim) / (2.0 * a);
	if (t1 > 0 && t2 > 0)
		return (t1 < t2 ? t1 : t2);
	if (t1 > 0)
		return (t1);
	if (t2 > 0)
		return (t2);
	return (-1);
}

/**
 * Calculates the t value for sphere-ray intersection.
 *
 * @param ray    Ray structure (origin and direction)
 * @param sphere Pointer to the sphere structure
 *
 * @return       t value for intersection, or -1 if no intersection
 */
double hit_sphere(t_ray ray, t_sphere *sphere)
{
	double	abc[3];
	double	discrim;

	get_sphere_coeffs(ray, sphere, abc);
	discrim = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discrim < 0)
		return (-1);
	return (get_nearest_t(abc[0], abc[1], sqrt(discrim)));
}