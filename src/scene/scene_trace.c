#include <float.h>
#include "main.h"
#include "utils/color/color.h"
#include "vector/vector.h"
#include "light/light.h"
#include "hit/hit.h"

/**
 * Traces a single ray and computes the color at the intersection point.
 * 
 * @param ray The ray to trace.
 * @param scene Pointer to the scene.
 * 
 * @return The computed color vector.
 */
static t_vec	trace_pixel(t_ray ray, t_scene *scene)
{
	t_hit_point	hit;
	t_vec		final_color;

	hit.min_t = DBL_MAX;
	min_sphere_t(scene->sphere, &ray, &hit);
	min_plane_t(scene->plane, &ray, &hit);
	min_cylinder_t(scene->cyl, &ray, &hit);
	if (hit.min_t == DBL_MAX)
		return ((t_vec){0, 0, 0});
	final_color.x = 0;
	final_color.y = 0;
	final_color.z = 0;
	calc_ambient_light(scene, &final_color, &hit);
	calc_phong_light(scene, &final_color, &hit, &ray);
	return (final_color);
}

/**
 * Traces multiple subpixels for anti-aliasing and averages the colors.
 * 
 * @param scene Pointer to the scene.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * 
 * @return The averaged color vector.
 */
static t_vec	trace_subpixels(t_scene *scene, int x, int y)
{
	t_ray	ray;
	t_vec	sum_color;
	int		grid_size;
	int		s_xy[2];
	double	sub_xy[2];

	grid_size = (int)sqrt(AA_SAMPLES);
	vec_assign(&sum_color, 0, 0, 0);
	s_xy[0] = -1;
	while (++s_xy[0] < grid_size)
	{
		s_xy[1] = -1;
		while (++s_xy[1] < grid_size)
		{
			sub_xy[0] = x + (s_xy[0] + 0.5) / grid_size;
			sub_xy[1] = y + (s_xy[1] + 0.5) / grid_size;
			ray = generate_ray(scene, sub_xy[0], sub_xy[1]);
			sum_color = vec_add(sum_color, trace_pixel(ray, scene));
		}
	}
	return (sum_color);
}

/**
 * Traces the entire scene, rendering each pixel with anti-aliasing and filling
 * the image buffer.
 * 
 * @param scene Pointer to the scene structure containing the image buffer and
 * scene data.
 * 
 * @return 0 on success.
 */
int	trace_scene(t_scene *scene)
{
	int		x;
	int		y;
	t_vec	sum_color;
	t_vec	avg_color;

	y = 0;
	while (y < (int)scene->height)
	{
		x = 0;
		while (x < (int)scene->width)
		{
			sum_color = trace_subpixels(scene, x, y);
			avg_color.x = sum_color.x / AA_SAMPLES;
			avg_color.y = sum_color.y / AA_SAMPLES;
			avg_color.z = sum_color.z / AA_SAMPLES;
			scene->image[y * scene->width + x] = to_mlx_color(&avg_color);
			x++;
		}
		y++;
	}
	return (0);
}
