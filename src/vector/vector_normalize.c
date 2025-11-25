#include "../include/vector/vector.h"

/**
 * Normalizes a vector to length 1.
 * 
 * @param v Vector
 * 
 * @return Resulting normalized vector or original (if length is 0)
 */
t_vec	vec_nrm(t_vec v)
{
	double	len;
	t_vec	result;

	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (len == 0)
		return (v);
	result.x = v.x / len;
	result.y = v.y / len;
	result.z = v.z / len;
	return (result);
}