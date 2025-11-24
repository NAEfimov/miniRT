#include "parser/parse.h"
#include "parser/read.h"
#include "utils/struct/struct.h"

#define CY_ARGS_NUM	6

void	parse_cylinder(t_scene *scene, char **w)
{
	t_cylinder	*c;
	t_list		*node;

	// Allocate a_light and initialise values
	c = malloc(sizeof(t_cylinder));
	if (!c)
		malloc_err(scene, w);
	// Check if ambient light already exists, and there are only 2 arguments
	if (split_size(w) != CY_ARGS_NUM)
		syntax_err(scene, w);
	// Try to read c.diameter and color
	if (read_vec(&c->coord, w[1]) || read_normal(&c->normal, w[2])
		|| read_double(&c->diameter, w[3]) || read_double(&c->height, w[4])
		|| read_color(&c->color, w[5]))
		syntax_err(scene, w);
	if (c->diameter < 0 || c->height < 0)
		syntax_err(scene, w);
	node = ft_lstnew(c);
	if (node == NULL)
	{
		free(c);
		malloc_err(scene, w);
	}
	ft_lstadd_back(&scene->cyl, node);
}
