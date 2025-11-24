#include "utils/copy_struct/copy_struct.h"

void	copy_color(t_color *dest, const t_color *src)
{
	dest->r = src->r;
	dest->g = src->g;
	dest->b = src->b;
}
