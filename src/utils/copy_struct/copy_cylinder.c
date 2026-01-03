#include "utils/copy_struct/copy_struct.h"

/**
 * Copies cylinder structure from source to destination.
 *
 * @param dest Pointer to destination cylinder structure
 * @param src Pointer to source cylinder structure
 */
void	copy_cylinder(t_cylinder *dest, const t_cylinder *src)
{
	copy_vec(&dest->coord, &src->coord);
	copy_vec(&dest->normal, &src->normal);
	dest->diameter = src->diameter;
	dest->height = src->height;
	copy_vec(&dest->color, &src->color);
}
