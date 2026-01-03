#include <stdlib.h>
#include "libft.h"
#include "main.h"

/**
 * Frees all dynamically allocated memory in the scene structure.
 *
 * @param scene Pointer to scene structure to clean
 *
 * @return 0 on success
 */
int	clean_scene(t_scene *scene)
{
	if (scene->image)
		free(scene->image);
	if (scene->line)
		free(scene->line);
	if (scene->camera)
		free(scene->camera);
	if (scene->a_light)
		free(scene->a_light);
	if (scene->light)
		free(scene->light);
	if (scene->sphere)
		ft_lstclear(&(scene->sphere), free);
	if (scene->cyl)
		ft_lstclear(&(scene->cyl), free);
	if (scene->plane)
		ft_lstclear(&(scene->plane), free);
	return (0);
}

/**
 * Frees an array of strings (words).
 *
 * @param words Array of strings to free
 */
void	clean_words(char **words)
{
	unsigned int	i;

	if (words == NULL)
		return ;
	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		++i;
	}
	free(words);
}
