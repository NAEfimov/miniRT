#include "utils/print/print.h"
#include <stdio.h>

/**
 * Prints plane information to stdout.
 *
 * @param plane Pointer to plane structure to print
 */
void	print_plane(t_plane *plane)
{
	if (!plane)
	{
		printf("Plane: NULL\n");
		return ;
	}
	printf("Plane:\n");
	print_vec(&plane->coord, "  Coord");
	print_vec(&plane->normal, "  Normal");
	print_color(&plane->color);
}
