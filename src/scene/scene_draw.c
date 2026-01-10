#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "MLX42/MLX42.h"

/**
 * Exits the program with an error message on MLX42 failure.
 * Prints the MLX42 error string to stderr and terminates the program.
 */
static void	ft_error(void)
{
	perror(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/**
 * Handles keyboard input for the MLX42 window.
 * Closes the window if the Escape key is pressed.
 * 
 * @param param Pointer to the MLX42 context (mlx_t).
 */
static void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

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

	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(scene->width, scene->height, "miniRT", false);
	if (!mlx)
	{
		clean_scene(scene);
		ft_error();
	}
	img = mlx_new_image(mlx, scene->width, scene->height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	{
		clean_scene(scene);
		ft_error();
	}
	memcpy(img->pixels, scene->image,
		img->width * img->height * sizeof(int32_t));
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
