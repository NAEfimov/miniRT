#include "parser/parse.h"

void	syntax_err(t_scene *scene, char **words)
{
	ft_putstr_fd("Error\nWrong scene description syntax\n", 2);
	clean_words(words);
	clean_scene(scene);
	exit(1);
}

void	malloc_err(t_scene *scene, char **words)
{
	ft_putstr_fd("Error: allocation failed \n", 2);
	clean_words(words);
	clean_scene(scene);
	exit(1);
}

int	split_size(char **words)
{
	int	size;

	if (!words)
		return (-1);
	size = 0;
	while (words[size])
		++size;
	return (size);
}
