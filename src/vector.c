#include "../include/vector.h"

/**
 * Adds two vectors component-wise.
 * 
 * @param a First vector
 * @param b Second vector
 * 
 * @return Resulting vector (a + b)
 */
t_vec	vec_add(t_vec a, t_vec b)
{
	t_vec	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

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