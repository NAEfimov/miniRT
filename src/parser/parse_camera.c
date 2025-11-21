#include "parser/parse.h"
#include "parser/read.h"
#include <stdio.h>

#define MIN_FOV 0
#define MAX_FOV 180

void	parse_camera(t_scene *scene, char **words)
{
	t_vec		r_coord;
	t_vec		r_orient;
	int			r_fov;

	// Check if camera already exists, and there are only 3 arguments
	if (scene->camera || !words[1] || !words[2] || !words[3] || words[4])
		syntax_err(scene, words);
	// printf("COORD: '%s'\n", words[1]);
	// printf("NORM: '%s'\n", words[2]);
	// printf("FOW: '%s'\n", words[3]);

	// Try to read coordinates, normal and fov
	if (read_vec(&r_coord, words[1]) || read_normal(&r_orient, words[2]) ||
		read_int(&r_fov, words[3]) || r_fov < MIN_FOV || r_fov > MAX_FOV)
	{
		syntax_err(scene, words);
	}
	// Allocate memory for the camera
	scene->camera = malloc(sizeof(t_camera));
	if (!scene->camera)
		malloc_err(scene, words);
	scene->camera->coord.x = r_coord.x;
	scene->camera->coord.y = r_coord.y;
	scene->camera->coord.z = r_coord.z;
	scene->camera->orient.x = r_orient.x;
	scene->camera->orient.y = r_orient.y;
	scene->camera->orient.z = r_orient.z;
	scene->camera->fov = r_fov;
	// printf("scene->camera->coord: %f, %f, %f\n", r_coord.x, r_coord.y, r_coord.z);
	// printf("scene->camera->norm:  %f, %f, %f\n", r_orient.x, r_orient.y, r_orient.z);
	// printf("scene->camera->fov:  %d\n\n", r_fov);
}
