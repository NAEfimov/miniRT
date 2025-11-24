#include "parser/parse.h"
#include "parser/read.h"

#define CY_ARGS_NUM	6

void	parse_cylinder(t_scene *scene, char **w)
{
	t_cylinder	c;
	t_cylinder	*cyl;

	// Check if ambient light already exists, and there are only 2 arguments
	if (split_size(w) != CY_ARGS_NUM)
		syntax_err(scene, w);
	// Try to read c.diameter and color
	if (read_vec(&c.coord, w[1]) || read_normal(&c.normal, w[2])
		|| read_double(&c.diameter, w[3]) || read_double(&c.height, w[4])
		|| read_color(&c.color, w[5]))
		syntax_err(scene, w);
	if (c.diameter < 0 || c.height < 0)
		syntax_err(scene, w);
	// Allocate a_light and initialise values
	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
		malloc_err(scene, w);
	cyl->coord.x = c.coord.x;
	cyl->coord.y = c.coord.y;
	cyl->coord.z = c.coord.z;
	cyl->normal.x = c.normal.x;
	cyl->normal.y = c.normal.y;
	cyl->normal.z = c.normal.z;
	cyl->diameter = c.diameter;
	cyl->height = c.height;
	cyl->color.r = c.color.r;
	cyl->color.g = c.color.g;
	cyl->color.b = c.color.b;
	ft_lstadd_back(&scene->cyl, ft_lstnew(cyl));
}
