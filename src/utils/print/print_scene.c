#include "utils/print/print.h"
#include "libft.h"
#include <stdio.h>

/**
 * Prints complete scene information to stdout.
 *
 * @param scene Pointer to scene structure to print
 */
void	print_scene(t_scene *scene)
{
	if (!scene)
	{
		printf("Scene: NULL\n");
		return ;
	}
	printf("Scene:\n");
	printf("  Width: %u\n", scene->width);
	printf("  Height: %u\n", scene->height);
	printf("  Image: %p\n", (void *)scene->image);
	print_camera(scene->camera);
	print_ambient_light(scene->a_light);
	print_light(scene->light);
	// Print lists if needed, but for brevity, just count
	printf("Spheres: %d\n", ft_lstsize(scene->sphere));
	printf("Planes: %d\n", ft_lstsize(scene->plane));
	printf("Cylinders: %d\n\n", ft_lstsize(scene->cyl));
	ft_lstiter(scene->sphere, (void (*)(void *))print_sphere);
	ft_lstiter(scene->plane, (void (*)(void *))print_plane);
	ft_lstiter(scene->cyl, (void (*)(void *))print_cylinder);
}
