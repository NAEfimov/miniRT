#include "main.h"
#include "../include/figures/figures.h"

static uint32_t	trace_pixel(t_ray ray, t_sphere *sphere, t_plane *plane)
{
	if (sphere && hit_sphere(ray, sphere))
		return (sphere->color.r << 24) |
			   (sphere->color.g << 16) | (sphere->color.b << 8) | 255;
	if (plane && hit_plane(ray, plane))
		return (plane->color.r << 24) |
			   (plane->color.g << 16) | (plane->color.b << 8) | 255;
	return 0x222222FF;
}

int	trace_scene(t_scene *scene)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_ray		ray;
	int			x;
	int			y;
	plane = NULL;
	sphere = NULL;
	if (scene->sphere)
		sphere = (t_sphere *)scene->sphere->content;
	if (scene->plane)
		plane = (t_plane *)scene->plane->content;
	y = 0;
	while (y < (int)scene->height)
	{
		x = 0;
		while (x < (int)scene->width)
		{
			ray = generate_ray(scene, x, y);
			scene->image[y * scene->width + x] = trace_pixel(ray, sphere, plane);
			x++;
		}
		y++;
	}
	return (0);
}
