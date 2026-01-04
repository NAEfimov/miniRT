#include "parser/parse.h"
#include "libft.h"

/**
 * Parses a scene element based on the identifier in the words array.
 *
 * @param scene Pointer to the scene structure
 * @param words Array of strings representing the parsed input line
 *
 * @return void
 *
 */
void	parse_scene_element(t_scene *scene, char **words)
{
	if (ft_strcmp(words[0], "A") == 0)
		parse_ambient_light(scene, words);
	else if (ft_strcmp(words[0], "C") == 0)
		parse_camera(scene, words);
	else if (ft_strcmp(words[0], "L") == 0)
		parse_light(scene, words);
	else if (ft_strcmp(words[0], "sp") == 0)
		parse_sphere(scene, words);
	else if (ft_strcmp(words[0], "pl") == 0)
		parse_plane(scene, words);
	else if (ft_strcmp(words[0], "cy") == 0)
		parse_cylinder(scene, words);
	else
		syntax_err(scene, words);
}
