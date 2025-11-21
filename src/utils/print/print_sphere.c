#include "utils/print/print.h"
#include <stdio.h>

void	print_sphere(t_sphere *sphere)
{
	if (!sphere)
	{
		printf("Sphere: NULL\n");
		return;
	}
	printf("Sphere:\n");
	print_vec(&sphere->coord, "  Coord");
	print_double(sphere->diameter, "  Diameter");
	print_color(&sphere->color);
}