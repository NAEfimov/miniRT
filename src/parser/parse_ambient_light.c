#include "parser/parse.h"
#include "parser/read.h"
#include "utils/print/print.h"
// #include <stdio.h>

#define	A_ARGS_NUM	3
#define MIN_RATIO 0.0
#define MAX_RATIO 1.0

void	parse_ambient_light(t_scene *scene, char **words)
{
	double	ratio;
	t_color	color;
	
	if (scene->a_light)
		syntax_err(scene, words);
	// Allocate a_light and initialise values
	scene->a_light = malloc(sizeof(t_amb_light));
	if (!scene->a_light)
		malloc_err(scene, words);

	// Check if ambient light already exists, and there are only 2 arguments
	// if (!words[1] || !words[2] || words[3])
	// 	syntax_err(scene, words);
	if (words_size(words) != A_ARGS_NUM)
		syntax_err(scene, words);

	// Try to read ratio and color
	if (read_double(&ratio, words[1]) || read_color(&color, words[2]))
		syntax_err(scene, words);

	// Check ratio for limits
	if (ratio < MIN_RATIO || ratio > MAX_RATIO)
		syntax_err(scene, words);

	scene->a_light->ratio = ratio;
	scene->a_light->color.r = color.r;
	scene->a_light->color.g = color.g;
	scene->a_light->color.b = color.b;
}
