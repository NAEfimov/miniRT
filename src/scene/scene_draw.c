#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "MLX42/MLX42.h"

/**
 * Exits the program with an error message on MLX42 failure.
 */
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// static void	ft_hook(void *param)
// {
// 	// const mlx_t* mlx = param;
// }

/**
 * Draws the scene using MLX42 library and displays it in a window.
 *
 * @param scene Pointer to scene structure containing image data
 *
 * @return 0 on success
 */
int	draw_scene(t_scene *scene)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(scene->width, scene->height, "miniRT", false);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	img = mlx_new_image(mlx, scene->width, scene->height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	memcpy(img->pixels, scene->image,
		img->width * img->height * sizeof(int32_t));

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
