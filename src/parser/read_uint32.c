#include "parser/read.h"

int	read_uint32(uint32_t *num, char *word)
{
	int	result;

	if (read_int(&result, word))
		return (1);
	if (result < 0)
		return (1);
	*num = (uint32_t)result;
	return (0);
}
