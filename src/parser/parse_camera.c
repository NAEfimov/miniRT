#include "parser/parse.h"
#include "parser/read.h"
#include <stdio.h>

#define	C_ARGS_NUM	4
#define MAX_FOV 180

void	parse_camera(t_scene *scene, char **words)
{
	t_camera	r;

	if (scene->camera)
		syntax_err(scene, words);
	
	// Check if camera already exists, and there are only 3 arguments
	if (scene->camera || words_size(words) != C_ARGS_NUM)
		syntax_err(scene, words);

	// Try to read coordinates, normal and fov
	if (read_vec(&r.coord, words[1]) || read_normal(&r.orient, words[2]) ||
		read_uint32(&r.fov, words[3]) || r.fov > MAX_FOV)
	{
		syntax_err(scene, words);
	}
	// Allocate memory for the camera
	scene->camera = malloc(sizeof(t_camera));
	if (!scene->camera)
		malloc_err(scene, words);
	scene->camera->coord.x = r.coord.x;
	scene->camera->coord.y = r.coord.y;
	scene->camera->coord.z = r.coord.z;
	scene->camera->orient.x = r.orient.x;
	scene->camera->orient.y = r.orient.y;
	scene->camera->orient.z = r.orient.z;
	scene->camera->fov = r.fov;
}
