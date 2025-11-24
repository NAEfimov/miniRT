#include "utils/struct/struct.h"

void	copy_vec(t_vec *dest, const t_vec *src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
}
