#include "utils/copy_struct/copy_struct.h"

/**
 * Copies vector structure from source to destination.
 *
 * @param dest Pointer to destination vector structure
 * @param src Pointer to source vector structure
 */
void	copy_vec(t_vec *dest, const t_vec *src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
}
