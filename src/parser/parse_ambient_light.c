#include "parser/parse.h"
#include "parser/read.h"
#include "utils/print/print.h"
#include "utils/copy_struct/copy_struct.h"

#define A_ARGS_NUM	3
#define MIN_RATIO 0.0
#define MAX_RATIO 1.0

void	parse_ambient_light(t_scene *scene, char **words)
{
	t_amb_light	r;

	if (scene->a_light)
		syntax_err(scene, words);
	// Check if ambient light already exists, and there are only 2 arguments
	if (split_size(words) != A_ARGS_NUM)
		syntax_err(scene, words);
	// Try to read ratio and color
	if (read_double(&r.ratio, words[1]) || read_color(&r.color, words[2]))
		syntax_err(scene, words);
	// Check ratio for limits
	if (r.ratio < MIN_RATIO || r.ratio > MAX_RATIO)
		syntax_err(scene, words);
	// Allocate a_light and initialise values
	scene->a_light = malloc(sizeof(t_amb_light));
	if (!scene->a_light)
		malloc_err(scene, words);
	copy_amb_light(scene->a_light, &r);
}
