#include "utils/copy_struct/copy_struct.h"

/**
 * Copies RGB color structure from source to destination.
 *
 * @param dest Pointer to destination RGB color structure
 * @param src Pointer to source RGB color structure
 */
void	copy_rgb_color(t_rgb_color *dest, const t_rgb_color *src)
{
	dest->r = src->r;
	dest->g = src->g;
	dest->b = src->b;
}
