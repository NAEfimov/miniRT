#include "../include/vector.h"

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

/**
 * Returns the length of a vector.
 *
 * @param v Vector
 *
 * @return Length
 */
double vec_len(t_vec v)
{
    return sqrt(vec_sq_len(v));
}