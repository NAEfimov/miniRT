#include "utils/print/print.h"
#include <stdio.h>

void	print_cylinder(t_cylinder *cyl)
{
	if (!cyl)
	{
		printf("Cylinder: NULL\n");
		return;
	}
	printf("Cylinder:\n");
	print_vec(&cyl->coord, "  Coordinates");
	print_vec(&cyl->normal, "  Normal");
	print_double(cyl->diameter, "  Diameter");
	print_double(cyl->height, "  Height");
	print_color(&cyl->color);
}