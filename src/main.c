#include "main.h"
#include "libft.h"

/**
 * Main entry point of the miniRT program.
 *
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 *
 * @return 0 on success
 */
int	main(int argc, char *argv[])
{
	t_scene	scene;

	check_args(argc, argv);
	read_scene(&scene, argv[1]);
	trace_scene(&scene);
	draw_scene(&scene);
	clean_scene(&scene);
	return (0);
}
