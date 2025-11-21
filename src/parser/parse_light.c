#include "parser/parse.h"
#include "parser/read.h"
// #include <stdio.h>

#define MIN_RATIO 0.0
#define MAX_RATIO 1.0

void	parse_light(t_scene *scene, char **words)
{
	t_vec	r_coord;
	double	r_bright;
	t_color	r_color;
	
	// Check if ambient light already exists, and there are only 2 arguments
	if (scene->light || !words[1] || !words[2] || !words[3] || words[4])
		syntax_err(scene, words);
	// printf("COORD: '%s'\n", words[1]);
	// printf("A_LIGHT: '%s'\n", words[2]);
	// printf("COLOR: '%s'\n", words[3]);

	// Try to read r_bright and color
	if (read_vec(&r_coord, words[1]) || read_double(&r_bright, words[2]) ||
		read_color(&r_color, words[3]))
	{
		syntax_err(scene, words);
	}
	// Check r_bright for limits
	if (r_bright < MIN_RATIO || r_bright > MAX_RATIO)
		syntax_err(scene, words);

	// Allocate a_light and initialise values
	scene->light = malloc(sizeof(t_light));
	if (!scene->light)
		malloc_err(scene, words);
	scene->light->coord.x = r_coord.x;
	scene->light->coord.y = r_coord.y;
	scene->light->coord.z = r_coord.z;
	scene->light->brigh = r_bright;
	scene->light->color.r = r_color.r;
	scene->light->color.g = r_color.g;
	scene->light->color.b = r_color.b;
	// printf("scene->light->coord: %f, %f, %f\n", r_coord.x, r_coord.y, r_coord.z);
	// printf("scene->light->ratio: %f\n", r_bright);
	// printf("scene->light->color: %d, %d, %d\n\n", r_color.r, r_color.g, r_color.b);
}
