#include "./parser/read.h"
#include <math.h>
#include <stdio.h>

#define EPSILON	1e-6

static int	is_normalized(t_vec *vec);

int	read_normal(t_vec *norm, char *word)
{
	t_vec vec;

	if (read_vec(&vec, word))
		return (1);
	if (!is_normalized(&vec))
		return (1);

	norm->x = vec.x;
	norm->y = vec.y;
	norm->z = vec.z;

	return (0);
}

static int	is_normalized(t_vec *vec)
{
	double length_squared;

	length_squared = vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
	// printf("length_squared: %f\n", length_squared);
	return (fabs(length_squared - 1.0) < EPSILON);
}
