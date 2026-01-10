#include "trace/trace.h"
#include "normal/normal.h"
#include "vector/vector.h"

/**
 * Calculates the normal vector at the intersection point on a sphere.
 *
 * @param point  The intersection point.
 * @param sphere Pointer to the sphere structure.
 *
 * @return       The normalized normal vector.
 */
t_vec sphere_normal(t_vec point, t_sphere *sphere)
{
    t_vec normal;

    normal = vec_sub(point, sphere->coord);
    return (vec_nrm(normal));
}

/**
 * Calculates the normal vector at the intersection point on a cylinder.
 * 
 * @param point The intersection point.
 * @param ray Pointer to the ray that hit the cylinder.
 * @param cyl Pointer to the cylinder structure.
 * 
 * @return The normalized normal vector.
 */
t_vec cylinder_normal(t_vec point, t_cylinder *cyl)
{
    t_vec	axis_point;
    double	dist_to_bottom;
    double	dist_to_top;
    double	proj;
    t_vec	to_point;

    to_point = vec_sub(point, cyl->coord);
    proj = vec_dot(to_point, cyl->normal);
    
    // Check if hit point is on bottom or top cap
    dist_to_bottom = fabs(proj + cyl->height * 0.5);
    dist_to_top = fabs(proj - cyl->height * 0.5);
    
    // If very close to bottom cap
    if (dist_to_bottom < 0.0001)
        return (cyl->normal);
    
    // If very close to top cap
    if (dist_to_top < 0.0001)
        return (cyl->normal);
    
    // Hit on the body - calculate radial normal
    axis_point = vec_add(cyl->coord, vec_scl(cyl->normal, proj));
    return (vec_nrm(vec_sub(point, axis_point)));
}

/**
 * Converts a normal vector to a color vector for visualization (normal map).
 * Maps normal components (-1 to 1) to color channels (0 to 1).
 *
 * @param normal The normalized normal vector.
 *
 * @return       The color vector representation of the normal.
 */
t_vec normal_to_color(t_vec normal)
{
    t_vec color;

    color.x = (normal.x + 1.0) * 0.5;
    color.y = (normal.y + 1.0) * 0.5;
    color.z = (normal.z + 1.0) * 0.5;

    return (color);
}

/**
 * Calculates the colored normal map at the intersection point on a sphere.
 *
 * @param point  The intersection point.
 * @param sphere Pointer to the sphere structure.
 *
 * @return       The color vector representation of the normal.
 */
t_vec sphere_normal_color(t_vec point, t_sphere *sphere)
{
    t_vec normal;

    normal = sphere_normal(point, sphere);
    return (normal_to_color(normal));
}
