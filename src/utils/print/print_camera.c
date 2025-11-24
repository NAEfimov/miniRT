#include "utils/print/print.h"
#include <stdio.h>

void	print_camera(t_camera *camera)
{
	if (!camera)
	{
		printf("Camera: NULL\n");
		return ;
	}
	printf("Camera:\n");
	print_vec(&camera->coord, "  Coord");
	print_vec(&camera->orient, "  Orient");
	print_uint32(camera->fov, "  FOV");
}
