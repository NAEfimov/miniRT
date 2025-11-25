#include "../include/vector/vector.h"

/**
 * Subtracts vector b from vector a.
 *
 * @param a First vector
 * @param b Second vector
 *
 * @return Resulting vector (a - b)
 */
t_vec vec_sub(t_vec a, t_vec b)
{
    t_vec result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}