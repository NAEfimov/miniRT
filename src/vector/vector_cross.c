#include "../include/vector/vector.h"

/**
 * Computes the cross product of two vectors.
 * 
 * @param a First vector
 * @param b Second vector
 * 
 * @return Resulting vector (a * b)
 */
t_vec	vec_crs(t_vec a, t_vec b)
{
	t_vec	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}