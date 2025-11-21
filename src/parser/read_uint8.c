#include "./parser/read.h"

int	read_uint8(uint8_t *num, char *word)
{
	int	result;

	if (read_int(&result, word))
		return (1);
	if (result < 0 || result > 255)
		return (1);
	*num = (uint8_t)result;
    return (0);
}
