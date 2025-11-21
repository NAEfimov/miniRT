#include "parser/parse.h"
#include "parser/read.h"
// #include <stdio.h>

#define	L_ARGS_NUM	4
#define MIN_RATIO 0.0
#define MAX_RATIO 1.0

void	parse_light(t_scene *scene, char **words)
{
	t_light	r;
	
	// Check if ambient light already exists, and there are only 2 arguments
	if (scene->light || words_size(words) != L_ARGS_NUM)
		syntax_err(scene, words);

	// Try to read r_bright and color
	if (read_vec(&r.coord, words[1]) || read_double(&r.brigh, words[2]) ||
		read_color(&r.color, words[3]))
	{
		syntax_err(scene, words);
	}
	// Check r_bright for limits
	if (r.brigh < MIN_RATIO || r.brigh > MAX_RATIO)
		syntax_err(scene, words);

	// Allocate a_light and initialise values
	scene->light = malloc(sizeof(t_light));
	if (!scene->light)
		malloc_err(scene, words);
	scene->light->coord.x = r.coord.x;
	scene->light->coord.y = r.coord.y;
	scene->light->coord.z = r.coord.z;
	scene->light->brigh = r.brigh;
	scene->light->color.r = r.color.r;
	scene->light->color.g = r.color.g;
	scene->light->color.b = r.color.b;
}
