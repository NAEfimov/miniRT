#include "main.h"
#include "libft.h"

int	main(void)
{
	t_scene	scene;
	
	read_scene(&scene);
	trace_scene(&scene);
	draw_scene(&scene);
	clean_scene(&scene);

	ft_putstr_fd("Libft\n", 0);
	
	return (0);
}