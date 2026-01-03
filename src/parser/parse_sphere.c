#include "parser/parse.h"
#include "parser/read.h"
#include "utils/copy_struct/copy_struct.h"

#define SP_ARGS_NUM	4
#define MIN_DIAMETER 0.0

/**
 * Parses the sphere from the input words and adds it to the scene.
 *
 * @param scene Pointer to the scene structure
 * @param words Array of strings representing the parsed input line
 *
 * @return void
 *
 */
void	parse_sphere(t_scene *scene, char **words)
{
	t_sphere	s;
	t_sphere	*sph;
	t_list		*node;

	// Check if ambient light already exists, and there are only 2 arguments
	if (split_size(words) != SP_ARGS_NUM)
		syntax_err(scene, words);
	// Try to read r_diameter and color
	if (read_vec(&s.coord, words[1]) || read_double(&s.diameter, words[2])
		|| read_color(&s.color, words[3]))
		syntax_err(scene, words);
	// Check r_diameter for limits
	if (s.diameter < MIN_DIAMETER)
		syntax_err(scene, words);
	// Allocate a_light and initialise values
	sph = malloc(sizeof(t_sphere));
	if (!sph)
		malloc_err(scene, words);
	copy_sphere(sph, &s);
	node = ft_lstnew(sph);
	if (node == NULL)
	{
		free(sph);
		malloc_err(scene, words);
	}
	ft_lstadd_back(&scene->sphere, node);
}
