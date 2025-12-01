#include "utils/copy_struct/copy_struct.h"

void	copy_plane(t_plane *dest, const t_plane *src)
{
	copy_vec(&dest->coord, &src->coord);
	copy_vec(&dest->normal, &src->normal);
	copy_rgb_color(&dest->color, &src->color);
}
