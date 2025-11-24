#include "utils/struct/struct.h"

void	copy_camera(t_camera *dest, const t_camera *src)
{
	copy_vec(&dest->coord, &src->coord);
	copy_vec(&dest->orient, &src->orient);
	dest->fov = src->fov;
}
