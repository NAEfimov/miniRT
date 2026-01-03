#include "utils/print/print.h"
#include <stdio.h>

/**
 * Prints a double value with a message to stdout.
 *
 * @param value The double value to print
 * @param msg The message prefix to print before the value
 */
void	print_double(double value, char *msg)
{
	printf("%s: %.3f\n", msg, value);
}
