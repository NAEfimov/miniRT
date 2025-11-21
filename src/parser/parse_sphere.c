#include "./parser/parse.h"
#include "parser/read.h"
// #include <stdio.h>

#define	SP_ARGS_NUM	4
#define MIN_DIAMETER 0.0

void	parse_sphere(t_scene *scene, char **words)
{
	t_sphere	r;
	t_sphere	*sph;
	
	// Check if ambient light already exists, and there are only 2 arguments
	if (words_size(words) != SP_ARGS_NUM)
		syntax_err(scene, words);

	// Try to read r_diameter and color
	if (read_vec(&r.coord, words[1]) || read_double(&r.diameter, words[2]) ||
		read_color(&r.color, words[3]))
	{
		syntax_err(scene, words);
	}
	// Check r_diameter for limits
	if (r.diameter < MIN_DIAMETER)
		syntax_err(scene, words);

	// Allocate a_light and initialise values
	sph = malloc(sizeof(t_sphere));
	if (!sph)
		malloc_err(scene, words);
	sph->coord.x = r.coord.x;
	sph->coord.y = r.coord.y;
	sph->coord.z = r.coord.z;
	sph->diameter = r.diameter;
	sph->color.r = r.color.r;
	sph->color.g = r.color.g;
	sph->color.b = r.color.b;
	ft_lstadd_back(&scene->sphere, ft_lstnew(sph));
}
