#include "utils/copy_struct/copy_struct.h"

void	copy_rgb_color(t_rgb_color *dest, const t_rgb_color *src)
{
	dest->r = src->r;
	dest->g = src->g;
	dest->b = src->b;
}
