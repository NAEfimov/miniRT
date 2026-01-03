#include "utils/copy_struct/copy_struct.h"

/**
 * Copies sphere structure from source to destination.
 *
 * @param dest Pointer to destination sphere structure
 * @param src Pointer to source sphere structure
 */
void	copy_sphere(t_sphere *dest, const t_sphere *src)
{
	copy_vec(&dest->coord, &src->coord);
	dest->diameter = src->diameter;
	copy_vec(&dest->color, &src->color);
}
