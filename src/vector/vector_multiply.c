#include "../include/vector/vector.h"

/**
 * Multiplies a vector by a vector.
 *
 * @param a Vector
 * @param b Vector
 *
 * @return Resulting vector (a * b)
 */
t_vec	vec_mul(t_vec a, t_vec b)
{
	t_vec	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return (result);
}