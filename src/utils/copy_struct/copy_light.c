#include "utils/copy_struct/copy_struct.h"

/**
 * Copies light structure from source to destination.
 *
 * @param dest Pointer to destination light structure
 * @param src Pointer to source light structure
 */
void	copy_light(t_light *dest, const t_light *src)
{
	copy_vec(&dest->coord, &src->coord);
	dest->brigh = src->brigh;
	copy_vec(&dest->color, &src->color);
}
