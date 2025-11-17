#include <stdlib.h>
#include "main.h"

int	read_scene(t_scene *scene, char *fname)
{
	(void)fname;
	scene->height = HEIGHT;
	scene->width = WIDTH;
	scene->image = malloc(scene->width * scene->height * sizeof(int32_t));
	if (scene->image == NULL)
		return(1);

	return (0);
}
