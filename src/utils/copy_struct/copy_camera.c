#include "utils/copy_struct/copy_struct.h"

/**
 * Copies camera structure from source to destination.
 *
 * @param dest Pointer to destination camera structure
 * @param src Pointer to source camera structure
 */
void	copy_camera(t_camera *dest, const t_camera *src)
{
	copy_vec(&dest->coord, &src->coord);
	copy_vec(&dest->orient, &src->orient);
	dest->fov = src->fov;
}
