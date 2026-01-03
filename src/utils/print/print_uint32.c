#include "utils/print/print.h"
#include <stdio.h>

/**
 * Prints a uint32_t value with a message to stdout.
 *
 * @param value The uint32_t value to print
 * @param msg The message prefix to print before the value
 */
void	print_uint32(uint32_t value, char *msg)
{
	printf("%s: %u\n", msg, value);
}
