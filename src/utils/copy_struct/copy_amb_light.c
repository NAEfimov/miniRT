#include "utils/copy_struct/copy_struct.h"

void	copy_amb_light(t_amb_light *dest, const t_amb_light *src)
{
	dest->ratio = src->ratio;
	copy_rgb_color(&dest->color, &src->color);
}
