#include "../include/trace/trace.h"
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

/**
 * Calculates the camera's orthonormal basis vectors.
 *
 * @param cam Pointer to camera structure
 *
 * @return Camera basis structure (forward, right, up)
 *
 */
static t_cam_basis	get_cam_basis(t_camera *cam)
{
	t_cam_basis	basis;
	t_vec		world_up;
	t_vec		temp_right;

	basis.forward = vec_nrm(cam->orient);
	world_up.x = 0.0;
	world_up.y = 1.0;
	world_up.z = 0.0;
	if (fabs(basis.forward.y) > 0.999)
	{
		world_up.x = 0.0;
		world_up.y = 0.0;
		world_up.z = 1.0;
	}
	temp_right = vec_crs(world_up, basis.forward);
	basis.right = vec_nrm(temp_right);
	basis.up = vec_nrm(vec_crs(basis.forward, basis.right));
	return (basis);
}

/**
 * Returns pixel offsets for (x, y).
 *
 * @param scene Scene pointer
 * @param x Pixel x coordinate
 * @param y Pixel y coordinate
 *
 * @return Structure with px and py
 */
static t_pixel_offset	get_pixel_offset(t_scene *scene, double x, double y)
{
	t_pixel_offset	off;
	double			aspect;
	double			fov_rad;

	aspect = (double)scene->width / (double)scene->height;
	fov_rad = scene->camera->fov * M_PI / 180.0;
	off.px = (2 * (x / scene->width) - 1) * tan(fov_rad / 2) * aspect;
	off.py = (1 - 2 * (y / scene->height)) * tan(fov_rad / 2);
	return (off);
}

/**
 * Calculates the camera's orthonormal basis vectors (forward, right, up).
 *
 * @param cam Pointer to camera structure
 *
 * @return Camera basis structure with forward, right, and up vectors
 */
t_ray	generate_ray(t_scene *scene, double x, double y)
{
	t_ray			ray;
	t_cam_basis		basis;
	t_pixel_offset	off;
	t_vec			dir;
	t_vec			up_scaled;

	basis = get_cam_basis(scene->camera);
	off = get_pixel_offset(scene, x, y);
	ray.origin = scene->camera->coord;
	dir = vec_scl(basis.right, off.px);
	dir = vec_add(basis.forward, dir);
	up_scaled = vec_scl(basis.up, off.py);
	dir = vec_add(dir, up_scaled);
	ray.direction = vec_nrm(dir);
	return (ray);
}
