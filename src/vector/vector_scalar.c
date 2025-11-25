#include "../include/vector/vector.h"

/**
 * Multiplies a vector by a scalar.
 * 
 * @param a Vector
 * @param s Scalar
 * 
 * @return Resulting vector (a * s)
 */
t_vec	vec_scl(t_vec a, double s)
{
	t_vec	result;

	result.x = a.x * s;
	result.y = a.y * s;
	result.z = a.z * s;
	return (result);
}