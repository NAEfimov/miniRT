#include "utils/copy_struct/copy_struct.h"

/**
 * Copies scene structure from source to destination.
 * Note: This performs a shallow copy of pointers.
 *
 * @param dest Pointer to destination scene structure
 * @param src Pointer to source scene structure
 */
void	copy_scene(t_scene *dest, const t_scene *src)
{
	dest->width = src->width;
	dest->height = src->height;
	dest->image = src->image;
	dest->camera = src->camera;
	dest->a_light = src->a_light;
	dest->light = src->light;
	dest->sphere = src->sphere;
	dest->plane = src->plane;
	dest->cyl = src->cyl;
}
