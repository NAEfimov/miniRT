#include "parser/parse.h"
#include "parser/read.h"
#include "utils/struct/struct.h"

#define PL_ARGS_NUM	4

void	parse_plane(t_scene *scene, char **words)
{
	t_plane	*p;
	t_list	*node;

	p = malloc(sizeof(t_plane));
	if (!p)
		malloc_err(scene, words);
	// Check if ambient light already exists, and there are only 2 arguments
	if (split_size(words) != PL_ARGS_NUM)
		syntax_err(scene, words);
	// Try to read r_diameter and color
	if (read_vec(&p->coord, words[1]) || read_normal(&p->normal, words[2])
		|| read_color(&p->color, words[3]))
		syntax_err(scene, words);
	// Allocate a_light and initialise values
	node = ft_lstnew(p);
	if (node == NULL)
	{
		free(p);
		malloc_err(scene, words);
	}
	ft_lstadd_back(&scene->plane, node);
}
