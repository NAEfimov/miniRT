// #include <stdio.h>
#include "./parser/parse.h"
#include "libft.h"

void parse_scene_element(t_scene *scene, char **words)
{
	// Print identifire
	// printf("IDENT: '%s'\n", words[0]);

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
