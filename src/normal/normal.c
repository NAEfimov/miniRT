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
