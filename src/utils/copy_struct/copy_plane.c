#include "utils/copy_struct/copy_struct.h"

/**
 * Copies plane structure from source to destination.
 *
 * @param dest Pointer to destination plane structure
 * @param src Pointer to source plane structure
 */
void	copy_plane(t_plane *dest, const t_plane *src)
{
	copy_vec(&dest->coord, &src->coord);
	copy_vec(&dest->normal, &src->normal);
	copy_vec(&dest->color, &src->color);
}
