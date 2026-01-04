#include "utils/copy_struct/copy_struct.h"

/**
 * Copies ambient light structure from source to destination.
 *
 * @param dest Pointer to destination ambient light structure
 * @param src Pointer to source ambient light structure
 */
void	copy_amb_light(t_amb_light *dest, const t_amb_light *src)
{
	dest->ratio = src->ratio;
	copy_vec(&dest->color, &src->color);
}
