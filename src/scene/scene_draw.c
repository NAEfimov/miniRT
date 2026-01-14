#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "mlx.h"

/**
 * Puts a pixel to the MLX image.
 *
 * @param data Pointer to MLX data structure
 * @param x X coordinate
 * @param y Y coordinate
 * @param color Color in uint32_t format
 */
static void	mlx_pixel_put_img(t_mlx_data *data, int x, int y, uint32_t color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * Handles key press events.
 *
 * @param keycode The key code pressed
 * @param param Pointer to MLX data
 *
 * @return 0 on success
 */
static int	handle_keypress(int keycode, void *param)
{
	t_mlx_data	*data;
	t_scene		*scene;

	scene = (t_scene *)param;
	data = &scene->mlx;
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		clean_scene(scene);
		exit(0);
	}
	return (0);
}

/**
 * Handles window close event.
 *
 * @param param Pointer to MLX data
 *
 * @return 0 on success
 */
static int	handle_close(void *param)
{
	t_mlx_data	*data;
	t_scene		*scene;

	scene = (t_scene *)param;
	data = &scene->mlx;
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clean_scene(scene);
	exit(0);
	return (0);
}

static void	init_mlx(t_scene *scene)
{
	scene->mlx.mlx = mlx_init();
	if (!scene->mlx.mlx)
	{
		clean_scene(scene);
		exit(EXIT_FAILURE);
	}
	scene->mlx.win = mlx_new_window(scene->mlx.mlx, scene->width,
			scene->height, "miniRT");
	scene->mlx.img = mlx_new_image(scene->mlx.mlx, scene->width, scene->height);
	scene->mlx.addr = mlx_get_data_addr(scene->mlx.img,
			&scene->mlx.bits_per_pixel, &scene->mlx.line_length,
			&scene->mlx.endian);
}

/**
 * Draws the scene using minilibx and displays it in a window.
 *
 * @param scene Pointer to scene structure containing image data
 *
 * @return 0 on success
 */
int	draw_scene(t_scene *scene)
{
	int	x;
	int	y;

	init_mlx(scene);
	y = 0;
	while (y < (int)scene->height)
	{
		x = 0;
		while (x < (int)scene->width)
		{
			mlx_pixel_put_img(&scene->mlx, x, y,
				scene->image[y * scene->width + x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win,
		scene->mlx.img, 0, 0);
	mlx_hook(scene->mlx.win, 2, 1L << 0, handle_keypress, scene);
	mlx_hook(scene->mlx.win, 17, 0, handle_close, scene);
	mlx_loop(scene->mlx.mlx);
	return (0);
}
