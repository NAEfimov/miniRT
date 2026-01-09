#include "../include/figures/figures.h"
#include <math.h>

/**
 * Checks if a ray intersects a sphere.
 *
 * @param ray    Ray structure (origin and direction).
 * @param sphere Pointer to the sphere structure.
 *
 * @return       1 if the ray intersects the sphere, 0 otherwise.
 *
 */
double calc_discrim(t_ray *ray, t_sphere *sphere, double *a, double *b)
{
	t_vec	oc;
	double	c;
	double	discrim;

	oc = vec_sub(ray->origin, sphere->coord);
	*a = vec_dot(ray->direction, ray->direction);
	*b = 2.0 * vec_dot(oc, ray->direction);
	c = vec_dot(oc, oc) - sphere->diameter * 0.5 * sphere->diameter * 0.5;
	discrim = (*b) * (*b) - 4 * (*a) * c;
	return (discrim);
}
/**
 * Computes the parameter t for the closest intersection point between a ray and a sphere.
 *
 * This function solves the quadratic equation for ray-sphere intersection and returns
 * the smallest positive t value if an intersection exists. If no valid intersection
 * is found (e.g., the ray misses the sphere or intersects behind the origin), it
 * returns -1.
 *
 * @param ray    The ray structure containing origin and direction.
 * @param sphere Pointer to the sphere structure containing center and diameter.
 *
 * @return       The parameter t for the closest intersection, or -1 if no intersection.
 */
double hit_sphere_t(t_ray ray, t_sphere *sphere)
{
    double	a;
    double	b;
    double	discrim;
    double	t1;
    double	t2;

    discrim = calc_discrim(&ray, sphere, &a, &b);
    if (discrim < 1e-6)
        return (-1);
    discrim = sqrt(discrim);
    t1 = (-b - discrim) / (2.0 * a);
    t2 = (-b + discrim) / (2.0 * a);
    if (t1 > 0 && t2 > 0)
        return (fmin(t1, t2));
    else if (t1 > 0)
        return (t1);
    else if (t2 > 0)
        return (t2);
    else
        return (-1);
}
