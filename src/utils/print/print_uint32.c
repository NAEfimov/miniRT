#include "utils/print/print.h"
#include <stdio.h>

void	print_uint32(uint32_t value, char *msg)
{
	printf("%s: %u\n", msg, value);
}
