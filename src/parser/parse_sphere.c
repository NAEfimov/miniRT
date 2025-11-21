#include "./parser/parse.h"
#include "parser/read.h"
// #include <stdio.h>

#define MIN_DIAMETER 0.0

void	parse_sphere(t_scene *scene, char **words)
{
	t_vec		r_coord;
	double		r_diameter;
	t_color		r_color;
	t_sphere	*sph;
	
	// Check if ambient light already exists, and there are only 2 arguments
	if (!words[1] || !words[2] || !words[3] || words[4])
		syntax_err(scene, words);
	// printf("COORD: '%s'\n", words[1]);
	// printf("DIAMETER: '%s'\n", words[2]);
	// printf("COLOR: '%s'\n", words[3]);

	// Try to read r_diameter and color
	if (read_vec(&r_coord, words[1]) || read_double(&r_diameter, words[2]) ||
		read_color(&r_color, words[3]))
	{
		syntax_err(scene, words);
	}
	// Check r_diameter for limits
	if (r_diameter < MIN_DIAMETER)
		syntax_err(scene, words);

	// Allocate a_light and initialise values
	sph = malloc(sizeof(t_sphere));
	if (!sph)
		malloc_err(scene, words);
	sph->coord.x = r_coord.x;
	sph->coord.y = r_coord.y;
	sph->coord.z = r_coord.z;
	sph->diameter = r_diameter;
	sph->color.r = r_color.r;
	sph->color.g = r_color.g;
	sph->color.b = r_color.b;
	ft_lstadd_back(&scene->sphere, ft_lstnew(sph));
	// printf("sphere->coord: %f, %f, %f\n", r_coord.x, r_coord.y, r_coord.z);
	// printf("sphere->diameter: %f\n", r_diameter);
	// printf("sphere->color: %d, %d, %d\n\n", r_color.r, r_color.g, r_color.b);
}
