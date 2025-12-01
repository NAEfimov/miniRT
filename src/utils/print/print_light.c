#include "utils/print/print.h"
#include <stdio.h>

void	print_light(t_light *light)
{
	if (!light)
	{
		printf("Light: NULL\n");
		return ;
	}
	printf("Light:\n");
	print_vec(&light->coord, "  Coord");
	print_double(light->brigh, "  Brightness");
	print_rgb_color(&light->color);
}
