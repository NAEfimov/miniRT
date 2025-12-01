#include "utils/print/print.h"
#include <stdio.h>

void	print_rgb_color(t_rgb_color color)
{
	printf("  RGB:   %u, %u, %u\n", color.r, color.g, color.b);
}

void	print_color(t_vec *color)
{
	print_vec(color, "  Color");
}
