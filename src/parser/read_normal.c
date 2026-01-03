#include "parser/read.h"
#include <math.h>

#define EPSILON	1e-6

static int	is_normalized(t_vec *vec);

/**
 * Reads a normalized vector (normal) from a string.
 *
 * @param norm Pointer to the vector to store the normal
 * @param word The input string containing the vector values
 *
 * @return 0 on success, 1 on failure
 *
 */
int	read_normal(t_vec *norm, char *word)
{
	t_vec	vec;

	if (read_vec(&vec, word))
		return (1);
	if (!is_normalized(&vec))
		return (1);
	norm->x = vec.x;
	norm->y = vec.y;
	norm->z = vec.z;
	return (0);
}

/**
 * Checks if a vector is normalized (has a length of approximately 1.0).
 *
 * @param vec Pointer to the vector to check
 *
 * @return 1 if normalized, 0 otherwise
 */
static int	is_normalized(t_vec *vec)
{
	double	length_squared;

	length_squared = vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
	return (fabs(length_squared - 1.0) < EPSILON);
}
