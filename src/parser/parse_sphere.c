#include "parser/parse.h"
#include "parser/read.h"
#include "utils/struct/struct.h"

#define SP_ARGS_NUM	4
#define MIN_DIAMETER 0.0

void	parse_sphere(t_scene *scene, char **words)
{
	t_sphere	*s;
	t_list		*node;

	// Allocate a_light and initialise values
	s = malloc(sizeof(t_sphere));
	if (!s)
		malloc_err(scene, words);
	// Check if ambient light already exists, and there are only 2 arguments
	if (split_size(words) != SP_ARGS_NUM)
		syntax_err(scene, words);
	// Try to read r_diameter and color
	if (read_vec(&s->coord, words[1]) || read_double(&s->diameter, words[2])
		|| read_color(&s->color, words[3]))
		syntax_err(scene, words);
	// Check r_diameter for limits
	if (s->diameter < MIN_DIAMETER)
		syntax_err(scene, words);
	// copy_sphere(sph, &r);
	node = ft_lstnew(s);
	if (node == NULL)
	{
		free(s);
		malloc_err(scene, words);
	}
	ft_lstadd_back(&scene->sphere, node);
}
