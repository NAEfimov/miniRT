#include "parser/parse.h"
#include "parser/read.h"

#define PL_ARGS_NUM	4

void	parse_plane(t_scene *scene, char **words)
{
	t_plane	r;
	t_plane	*pln;

	// Check if ambient light already exists, and there are only 2 arguments
	if (split_size(words) != PL_ARGS_NUM)
		syntax_err(scene, words);
	// Try to read r_diameter and color
	if (read_vec(&r.coord, words[1]) || read_normal(&r.normal, words[2])
		|| read_color(&r.color, words[3]))
		syntax_err(scene, words);
	// Allocate a_light and initialise values
	pln = malloc(sizeof(t_plane));
	if (!pln)
		malloc_err(scene, words);
	pln->coord.x = r.coord.x;
	pln->coord.y = r.coord.y;
	pln->coord.z = r.coord.z;
	pln->normal.x = r.normal.x;
	pln->normal.y = r.normal.y;
	pln->normal.z = r.normal.z;
	pln->color.r = r.color.r;
	pln->color.g = r.color.g;
	pln->color.b = r.color.b;
	ft_lstadd_back(&scene->plane, ft_lstnew(pln));
}
