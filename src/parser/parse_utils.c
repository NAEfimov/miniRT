#include "parser/parse.h"

/**
 * Handles syntax errors by printing an error message and cleaning up.
 *
 * @param scene Pointer to the scene structure
 * @param words Array of strings to clean up
 *
 * @return void
 *
 */
void	syntax_err(t_scene *scene, char **words)
{
	ft_putstr_fd("Error\nWrong scene description syntax\n", 2);
	clean_words(words);
	clean_scene(scene);
	exit(1);
}

/**
 * Handles memory allocation errors by printing an error message and cleaning up.
 *
 * @param scene Pointer to the scene structure
 * @param words Array of strings to clean up
 *
 * @return void
 *
 */
void	malloc_err(t_scene *scene, char **words)
{
	ft_putstr_fd("Error: allocation failed \n", 2);
	clean_words(words);
	clean_scene(scene);
	exit(1);
}

/**
 * Calculates the number of elements in a null-terminated array of strings.
 *
 * @param words Array of strings
 *
 * @return The size of the array, or -1 if words is NULL
 *
 */
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
