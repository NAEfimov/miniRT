#include "utils/print/print.h"
#include <stdio.h>

/**
 * Prints sphere information to stdout.
 *
 * @param sphere Pointer to sphere structure to print
 */
void	print_sphere(t_sphere *sphere)
{
	if (!sphere)
	{
		printf("Sphere: NULL\n");
		return ;
	}
	printf("Sphere:\n");
	print_vec(&sphere->coord, "  Coord");
	print_double(sphere->diameter, "  Diameter");
	print_color(&sphere->color);
}
