#include <stdio.h>
#include "./parser/parse.h"

void	rm_nline_char(char **str_ptr);

// Parce line with ft_split
void	parse_line(t_scene *scene, char *line)
{
	char	**words;

	rm_nline_char(&line);
	words = ft_split(line, ' ');
	if (words == NULL)
	{
		ft_putstr_fd("ft_split(): error\n", 2);
		clean_scene(scene);
		exit(1);
	}
	if (words[0])
	{
		// Print line
		printf("LINE: '%s'\n", line);

		parse_scene_element(scene, words);

		clean_words(words);
	}
}

void	rm_nline_char(char **str_ptr)
{
	size_t	i;
	char	*str;

	str = *str_ptr;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		++i;
	}
}
