#include "../include/vector/vector.h"

/**
 * Returns the squared length of a vector.
 *
 * @param v Vector
 *
 * @return Squared length
 */
double vec_sq_len(t_vec v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}