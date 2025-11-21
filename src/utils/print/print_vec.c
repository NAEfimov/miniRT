#include "utils/print/print.h"
#include <stdio.h>

void	print_vec(t_vec *vec, char *msg)
{
	if (!vec)
	{
		printf("%s: NULL\n", msg);
		return;
	}
	printf("%s: %.3f, %.3f, %.3f\n", msg, vec->x, vec->y, vec->z);
}