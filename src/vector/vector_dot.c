#include "../include/vector/vector.h"

/**
 * Computes the dot product of two vectors.
 *
 * @param a First vector
 * @param b Second vector
 *
 * @return Scalar dot product
 */
double vec_dot(t_vec a, t_vec b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}