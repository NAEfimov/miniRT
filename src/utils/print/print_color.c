#include "utils/print/print.h"
#include <stdio.h>

/**
 * Prints RGB color components to stdout.
 *
 * @param color RGB color structure to print
 */
void	print_rgb_color(t_rgb_color color)
{
	printf("  RGB:   %u, %u, %u\n", color.r, color.g, color.b);
}

/**
 * Prints color vector to stdout.
 *
 * @param color Pointer to color vector to print
 */
void	print_color(t_vec *color)
{
	print_vec(color, "  Color");
}
