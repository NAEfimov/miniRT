#include "light/light.h"
#include "hit/hit.h"

/**
 * Calculates and adds the ambient light contribution to the final color.
 * 
 * @param scene Pointer to the scene.
 * @param final_color Pointer to the final color vector to modify.
 * @param hit Pointer to the hit point.
 */
void	calc_ambient_light(t_scene *scene, t_vec *final_color, t_hit_point *hit)
{
	t_vec	ambient;

	if (scene->a_light)
	{
		ambient = vec_scl(scene->a_light->color, scene->a_light->ratio);
		*final_color = vec_add(*final_color, vec_mul(ambient, hit->obj_color));
	}
}

/**
 * Calculates diffuse lighting contribution using Lambert's cosine law.
 */
static void calc_diffuse_component(t_scene *scene, t_vec *fnl_color, t_hit_point *hit, t_phong_light *ph_light)
{
	t_vec   diffuse;

	ph_light->attenuation = 1.0 / (ph_light->l_dist * ph_light->l_dist);
	ph_light->dot_nl = vec_dot(hit->normal, ph_light->l_dir);
	if (ph_light->dot_nl > 0)
	{
		// diffuse = vec_scl(scene->light->color, scene->light->brigh * ph_light->dot_nl * ph_light->attenuation);
		diffuse = vec_scl(scene->light->color, scene->light->brigh * ph_light->dot_nl);
		*fnl_color = vec_add(*fnl_color, vec_mul(diffuse, hit->obj_color));
	}
}

/**
 * Calculates specular lighting contribution using Phong reflection model.
 */
static void calc_specular_component(t_scene *scene, t_vec *fnl_color, t_hit_point *hit, t_ray *ray, t_phong_light *ph_light)
{
    t_vec   view_dir;
    t_vec   reflect_dir;
    t_vec   specular;

    view_dir = vec_nrm(vec_sub(ray->origin, hit->point));
    reflect_dir = vec_sub(vec_scl(hit->normal, 2 * ph_light->dot_nl), ph_light->l_dir);
    ph_light->dot_rv = vec_dot(reflect_dir, view_dir);
    if (ph_light->dot_rv > 0)
    {
        specular = vec_scl(scene->light->color, scene->light->brigh * pow(ph_light->dot_rv, SHINE) * ph_light->attenuation);
        *fnl_color = vec_add(*fnl_color, specular);
    }
}

/**
 * Calculates and adds diffuse and specular lighting contributions to the final color.
 * 
 * @param scene Pointer to the scene.
 * @param fnl_color Pointer to the final color vector to modify.
 * @param hit Pointer to the hit point.
 * @param ray Pointer to the viewing ray.
 */

void	calc_phong_lightning(t_scene *scene, t_vec *fnl_color, t_hit_point *hit, t_ray *ray)
{
    t_phong_light ph_light;

	if (scene->light)
	{
		ph_light.l_dir = vec_sub(scene->light->coord, hit->point);
		ph_light.l_dist = vec_len(ph_light.l_dir);
		ph_light.l_dir = vec_nrm(ph_light.l_dir);

        ph_light.eps = fmax(0.001, ph_light.l_dist * 0.0001);
		ph_light.sh_ray.origin = vec_add(hit->point, vec_scl(hit->normal, ph_light.eps));
		ph_light.sh_ray.direction = ph_light.l_dir;

		if (!hits_any_object(scene, ph_light.sh_ray, ph_light.l_dist))
		{
			ph_light.attenuation = 1.0 / (ph_light.l_dist * ph_light.l_dist);
			ph_light.dot_nl = vec_dot(hit->normal, ph_light.l_dir);

            // diffuse
			calc_diffuse_component(scene, fnl_color, hit, &ph_light);
            // Specular
            calc_specular_component(scene, fnl_color, hit, ray, &ph_light);
		}
	}
}
