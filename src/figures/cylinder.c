#include "../include/figures/figures.h"
#include <math.h>

/**
 * Calculates quadratic coefficients for infinite cylinder-ray intersection.
 *
 * @param ray Ray structure (origin and direction)
 * @param cyl Pointer to the cylinder structure
 * @param oc  Vector from cylinder axis point to ray origin
 * @param abc Array to store coefficients [a, b, c]
 */
static void get_cylinder_coeffs(t_ray ray, t_cylinder *cyl, t_vec oc, double abc[3])
{
    t_vec	dir_proj;
    t_vec	oc_proj;
    double	radius;
    double  scalar_proj;

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
static int is_within_cylinder_height(t_ray ray, t_cylinder *cyl, double t)
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
 * Tests intersection with a cylinder cap (circle).
 *
 * @param ray Ray structure
 * @param cyl Cylinder structure
 *
 * @return Distance t to nearest cap intersection, or -1 if no hit
 */
static double hit_cylinder_cap(t_ray ray, t_cylinder *cyl, t_vec cap_center, double	denom)
{
    // double	denom;
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
        to_hit = vec_sub(vec_add(ray.origin, vec_scl(ray.direction, t)), cap_center);
        dist_sq = vec_dot(to_hit, to_hit) - pow(vec_dot(to_hit, cyl->normal), 2);
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
static double hit_cylinder_caps(t_ray ray, t_cylinder *cyl)
{
    double	denom;
    t_vec	cap_center;
    double	t_bottom;
    double	t_top;

    t_bottom = -1;
    t_top = -1;
    denom = vec_dot(cyl->normal, ray.direction);
    
    if (fabs(denom) > 1e-6)
    {
        // Bottom cap
        cap_center = vec_sub(cyl->coord, vec_scl(cyl->normal, cyl->height * 0.5));
        t_bottom = hit_cylinder_cap(ray, cyl, cap_center, denom);

        // Top cap
        cap_center = vec_add(cyl->coord, vec_scl(cyl->normal, cyl->height * 0.5));
        t_top = hit_cylinder_cap(ray, cyl, cap_center, denom);

    }
    
    return (min_pos_value(t_bottom, t_top));
}

/**
 * Tests intersection with cylinder body.
 *
 * @param ray Ray structure
 * @param cyl Cylinder structure
 *
 * @return Distance t to nearest body intersection, or -1 if no hit
 */
static double hit_cylinder_body(t_ray ray, t_cylinder *cyl)
{
    double	abc[3];
    double	discrim;
    t_vec	oc;
    double	t1;
    double	t2;

    oc = vec_sub(ray.origin, cyl->coord);
    get_cylinder_coeffs(ray, cyl, oc, abc);
    
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

/**
 * Calculates the intersection distance t for a ray and cylinder.
 *
 * @param ray Ray structure (origin and direction).
 * @param cyl Pointer to the cylinder structure.
 *
 * @return    Intersection distance t (>0 if hit, -1 otherwise).
 */
double hit_cylinder(t_ray ray, t_cylinder *cyl)
{
    double	t_body;
    double	t_caps;

    t_body = hit_cylinder_body(ray, cyl);
    t_caps = hit_cylinder_caps(ray, cyl);
    
    return (min_pos_value(t_body, t_caps));
}
