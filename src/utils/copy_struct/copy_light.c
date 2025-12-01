#include "utils/copy_struct/copy_struct.h"

void	copy_light(t_light *dest, const t_light *src)
{
	copy_vec(&dest->coord, &src->coord);
	dest->brigh = src->brigh;
	copy_rgb_color(&dest->color, &src->color);
}
