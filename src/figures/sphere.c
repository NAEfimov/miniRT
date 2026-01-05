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
double hit_sphere_t(t_ray ray, t_sphere *sphere)
{
    t_vec	oc;
    double	a;
    double	b;
    double	c;
    double	discrim;
    double	t1;
    double	t2;

    oc = vec_sub(ray.origin, sphere->coord);
    a = vec_dot(ray.direction, ray.direction);
    b = 2.0 * vec_dot(oc, ray.direction);
    c = vec_dot(oc, oc) - sphere->diameter * 0.5 * sphere->diameter * 0.5;
    discrim = b * b - 4 * a * c;
    if (discrim < 0)
        return (-1);
    discrim = sqrt(discrim);
    t1 = (-b - discrim) / (2.0 * a);
    t2 = (-b + discrim) / (2.0 * a);
    if (t1 > 0 && t2 > 0)
        return (t1 < t2 ? t1 : t2);
    else if (t1 > 0)
        return (t1);
    else if (t2 > 0)
        return (t2);
    else
        return (-1);
}
