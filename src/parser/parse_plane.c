#include "parser/parse.h"
#include "parser/read.h"
#include "utils/copy_struct/copy_struct.h"

#define PL_ARGS_NUM	4

/**
 * Parses the plane from the input words and adds it to the scene.
 *
 * @param scene Pointer to the scene structure
 * @param words Array of strings representing the parsed input line
 *
 * @return void
 *
 */
void	parse_plane(t_scene *scene, char **words)
{
	t_plane	p;
	t_plane	*pln;
	t_list	*node;

	if (split_size(words) != PL_ARGS_NUM)
		syntax_err(scene, words);
	if (read_vec(&p.coord, words[1]) || read_normal(&p.normal, words[2])
		|| read_color(&p.color, words[3]))
		syntax_err(scene, words);
	pln = malloc(sizeof(t_plane));
	if (!pln)
		malloc_err(scene, words);
	copy_plane(pln, &p);
	node = ft_lstnew(pln);
	if (node == NULL)
	{
		free(pln);
		malloc_err(scene, words);
	}
	ft_lstadd_back(&scene->plane, node);
}
