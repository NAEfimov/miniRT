#include "main.h"
#include "libft.h"

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
