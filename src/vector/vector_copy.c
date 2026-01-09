#include "../include/vector/vector.h"

/**
 * Copies the values from one vector to another.
 *
 * @param v The source vector
 *
 * @return A copy of the vector
 */
void vec_copy(t_vec *dist, const t_vec *source)
{
	dist->x = source->x;
	dist->y = source->y;
	dist->z = source->z;
}