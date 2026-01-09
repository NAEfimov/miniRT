#include "../include/vector/vector.h"

/**
 * Assigns values to a vector.
 *
 * @param x The x component
 * @param y The y component
 * @param z The z component
 *
 * @return The resulting vector
 */
t_vec vec_assign(double x, double y, double z)
{
    t_vec result;

    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}