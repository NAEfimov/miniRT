#include <stdlib.h>
#include "main.h"

int	clean_scene(t_scene *scene)
{
	if (scene->image)
		free(scene->image);

	return (0);
}