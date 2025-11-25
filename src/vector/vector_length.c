#include "../include/vector/vector.h"

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