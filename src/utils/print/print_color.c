#include "utils/print/print.h"
#include <stdio.h>

void	print_color(t_color *color)
{
	if (!color)
	{
		printf("  Color: NULL\n");
		return ;
	}
	printf("  Color: %u, %u, %u\n", color->r, color->g, color->b);
}
