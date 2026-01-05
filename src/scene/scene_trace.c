#include "main.h"
#include "../include/figures/figures.h"
#include "utils/color/color.h"
#include "vector/vector.h"
#include "normal/normal.h"

static uint32_t	trace_pixel(t_ray ray, t_sphere *sphere, t_plane *plane)
{
	double	t;
	t_vec	point;
	t_vec	norm_color;

	if (sphere && hit_sphere_t(ray, sphere) >= 0)
	{
		t = hit_sphere_t(ray, sphere);
		if (t >= 0)
		{
			point = vec_add(ray.origin, vec_scl(ray.direction, t));
			norm_color = sphere_normal_color(point, sphere);
			return (to_mlx_color(&norm_color));
		}
		// return (to_mlx_color(&sphere->color));
	}
	if (plane && hit_plane(ray, plane))
		return (to_mlx_color(&plane->color));
	return 0x222222FF;
}

/**
 * Traces the scene by filling the image buffer with test data.
 *
 * @param scene Pointer to scene structure containing image buffer
 *
 * @return 0 on success
 */
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
