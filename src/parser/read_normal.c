#include "./parser/read.h"

int	read_normal(t_vec *norm, char *word)
{
	t_vec vec;

	if (read_vec(&vec, word))
		return (1);
	if (vec.x < 0 || vec.x > 1 ||
		vec.y < 0 || vec.y > 1 ||
		vec.z < 0 || vec.z > 1)
	{
		return (1);
	}
	norm->x = vec.x;
	norm->y = vec.y;
	norm->z = vec.z;

	return (0);
}