#include "utils/copy_struct/copy_struct.h"

void	copy_sphere(t_sphere *dest, const t_sphere *src)
{
	copy_vec(&dest->coord, &src->coord);
	dest->diameter = src->diameter;
	copy_rgb_color(&dest->color, &src->color);
}
