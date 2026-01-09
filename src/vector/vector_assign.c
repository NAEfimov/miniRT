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
void	vec_assign(t_vec *vec, double x, double y, double z)
{
	if (!vec)
		return ;
	vec->x = x;
	vec->y = y;
	vec->z = z;
}