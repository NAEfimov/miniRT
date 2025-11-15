#include "main.h"

int	main(void)
{
	t_scene	scene;
	
	read_scene(&scene);
	trace_scene(&scene);
	draw_scene(&scene);
	clean_scene(&scene);
	
	return (0);
}