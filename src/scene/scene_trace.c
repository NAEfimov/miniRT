#include "main.h"

/**
 * Traces the scene by filling the image buffer with test data.
 *
 * @param scene Pointer to scene structure containing image buffer
 *
 * @return 0 on success
 */
int	trace_scene(t_scene *scene)
{
	int32_t	i;

	i = -1;
	while (++i < (int32_t)(scene->width * scene->height))
	{
		(scene->image)[i] = i << 26;
	}
	// memset(image, 122, img->width * img->height * sizeof(int32_t));

	return (0);
}
