#include "utils/struct/struct.h"

void	copy_cylinder(t_cylinder *dest, const t_cylinder *src)
{
	copy_vec(&dest->coord, &src->coord);
	copy_vec(&dest->normal, &src->normal);
	dest->diameter = src->diameter;
	dest->height = src->height;
	copy_color(&dest->color, &src->color);
}
