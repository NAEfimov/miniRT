#include "parser/read.h"

/**
 * Parses a string into an unsigned 32-bit integer value.
 *
 * @param num Pointer to the uint32_t to store the parsed value
 * @param word The input string to parse
 *
 * @return 0 on success, 1 on failure
 *
 */
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
