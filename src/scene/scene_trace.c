#include "main.h"
#include <float.h>
#include "../include/figures/figures.h"
#include "utils/color/color.h"
#include "vector/vector.h"
#include "normal/normal.h"

// Helper function to check if a ray hits any object within max_t
static int hits_any_object(t_scene *scene, t_ray ray, double max_t)
{
    t_list *current;

    // Check spheres
    current = scene->sphere;
    while (current)
    {
        t_sphere *sph = (t_sphere *)current->content;
        double t = hit_sphere_t(ray, sph);
        if (t > 0.001 && t < max_t)
            return 1;
        current = current->next;
    }

    // Check planes
    current = scene->plane;
    while (current)
    {
        t_plane *pln = (t_plane *)current->content;
        double t = hit_plane_t(ray, pln);
        if (t > 0.001 && t < max_t)
            return 1;
        current = current->next;
    }

    // Add cylinders when implemented
    // current = scene->cyl;
    // while (current) { ... }

    return 0;
}

static void	min_sphere_t(t_list	*current, t_ray *ray, t_hit_point *hit)
{
	double		t;
	t_sphere	*sph;
	t_vec		oc;

	while (current)
	{
		sph = (t_sphere *)current->content;
		t = hit_sphere_t(*ray, sph);
		if (t > 0 && t < hit->min_t)
		{
			hit->min_t = t;
			hit->point = vec_add(ray->origin, vec_scl(ray->direction, t));
			hit->normal = sphere_normal(hit->point, sph);
			// Flip normal if we're hitting from inside the sphere
            oc = vec_sub(ray->origin, sph->coord);
            if (vec_dot(oc, oc) < (sph->diameter * 0.5 * sph->diameter * 0.5))
                hit->normal = vec_scl(hit->normal, -1.0);
			hit->obj_color = sph->color;
		}
		current = current->next;
	}
}

static void	min_plane_t(t_list	*current, t_ray *ray, t_hit_point *hit)
{
	double		t;
	t_plane		*pln;

	while (current)
	{
		pln = (t_plane *)current->content;
		t = hit_plane_t(*ray, pln);
		if (t > 0 && t < hit->min_t)
		{
			hit->min_t = t;
			hit->point = vec_add(ray->origin, vec_scl(ray->direction, t));
			hit->normal = pln->normal;
			// Flip normal if it points away from the ray (two-sided plane)
			if (vec_dot(hit->normal, ray->direction) > 0)
    			hit->normal = vec_scl(hit->normal, -1.0);
			hit->obj_color = pln->color;
		}
		current = current->next;
	}
}

void	calc_ambient_light(t_scene *scene, t_vec *final_color, t_hit_point *hit)
{
	t_vec	ambient;

	if (scene->a_light)
	{
		ambient = vec_scl(scene->a_light->color, scene->a_light->ratio);
		*final_color = vec_add(*final_color, vec_mul(ambient, hit->obj_color));
	}
}

void	calc_light(t_scene *scene, t_vec *final_color, t_hit_point *hit)
{
	t_vec	light_dir;
	double	light_dist;
	t_ray	shadow_ray;
	double	epsilon;

	if (scene->light)
	{
		light_dir = vec_sub(scene->light->coord, hit->point);
		light_dist = vec_len(light_dir);
		light_dir = vec_nrm(light_dir);

		// Use adaptive epsilon based on distance to avoid self-intersection
        epsilon = fmax(0.001, light_dist * 0.0001);
		// Offset the shadow ray origin to avoid self-intersection
		shadow_ray.origin = vec_add(hit->point, vec_scl(hit->normal, epsilon));
		shadow_ray.direction = light_dir;

		if (!hits_any_object(scene, shadow_ray, light_dist))
		{
			double dot_nl = vec_dot(hit->normal, light_dir);
            if (dot_nl > 0)
            {
                t_vec diffuse = vec_scl(scene->light->color, scene->light->brigh * dot_nl);
                *final_color = vec_add(*final_color, vec_mul(diffuse, hit->obj_color));
            }

            // // Specular (optional)
            // t_vec view_dir = vec_nrm(vec_sub(ray->origin, hit->point));
            // t_vec reflect_dir = vec_sub(vec_scl(hit->normal, 2 * dot_nl), light_dir);
            // double dot_rv = vec_dot(reflect_dir, view_dir);
            // if (dot_rv > 0)
            // {
            //     double shininess = 32.0;
            //     t_vec specular = vec_scl(scene->light->color, scene->light->brigh * pow(dot_rv, shininess) * attenuation);
            //     *final_color = vec_add(*final_color, specular);
            // }
		}
	}
}

static t_vec	trace_pixel(t_ray ray, t_scene *scene)
{
	t_hit_point hit;
	t_vec		final_color;

	hit.min_t = DBL_MAX;

	min_sphere_t(scene->sphere, &ray, &hit);
	min_plane_t(scene->plane, &ray, &hit);
	// min_cylinder_t(scene->cyl, &ray, &hit);
	if (hit.min_t == DBL_MAX)
		return ((t_vec){0, 0, 0});

	final_color.x = 0;
	final_color.y = 0;
	final_color.z = 0;
	calc_ambient_light(scene, &final_color, &hit);
	calc_light(scene, &final_color, &hit);
	
	return (final_color);
}

static t_vec trace_subpixels(t_scene *scene, int x, int y)
{
	t_ray	ray;
	t_vec	sum_color;
	int		grid_size;
	int		sx;
	int		sy;
	double	subx;
	double	suby;

	grid_size = (int)sqrt(AA_SAMPLES);
	vec_assign(&sum_color, 0, 0, 0);
	sx = -1;
	while (++sx < grid_size)
	{
		sy = -1;
		while (++sy < grid_size)
		{
			subx = x + (sx + 0.5) / grid_size;
			suby = y + (sy + 0.5) / grid_size;
			ray = generate_ray(scene, subx, suby);
			sum_color = vec_add(sum_color, trace_pixel(ray, scene));
		}
	}
	return (sum_color);
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
    int x;
    int y;
    t_vec sum_color;
    t_vec avg_color;

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
