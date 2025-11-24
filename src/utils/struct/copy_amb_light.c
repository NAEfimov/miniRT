#include "utils/struct/struct.h"

void	copy_amb_light(t_amb_light *dest, const t_amb_light *src)
{
	dest->ratio = src->ratio;
	copy_color(&dest->color, &src->color);
}
