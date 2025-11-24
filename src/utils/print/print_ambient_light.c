#include "utils/print/print.h"
#include <stdio.h>

void	print_ambient_light(t_amb_light *a_light)
{
	if (!a_light)
	{
		printf("Ambient Light: NULL\n");
		return ;
	}
	printf("Ambient Light:\n");
	print_double(a_light->ratio, "  Ratio");
	print_color(&a_light->color);
}
