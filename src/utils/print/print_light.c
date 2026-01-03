#include "utils/print/print.h"
#include <stdio.h>

/**
 * Prints light information to stdout.
 *
 * @param light Pointer to light structure to print
 */
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
	print_color(&light->color);
}
