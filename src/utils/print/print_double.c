#include "utils/print/print.h"
#include <stdio.h>

void	print_double(double value, char *msg)
{
	printf("%s: %.3f\n", msg, value);
}
