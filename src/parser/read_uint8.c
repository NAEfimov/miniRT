#include "parser/read.h"

/**
 * Parses a string into an unsigned 8-bit integer value (0-255).
 *
 * @param num Pointer to the uint8_t to store the parsed value
 * @param word The input string to parse
 *
 * @return 0 on success, 1 on failure
 *
 */
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
