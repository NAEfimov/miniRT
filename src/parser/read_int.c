#include "parser/read.h"

/**
 * Parses a string into an integer value.
 *
 * @param num Pointer to the int to store the parsed value
 * @param word The input string to parse
 *
 * @return 0 on success, 1 on failure
 *
 */
int	read_int(int *num, char *word)
{
	int	sign;
	int	result;

	if (!word || !*word || !num)
		return (1);
	sign = read_sign(&word);
	if (*word < '0' || *word > '9')
		return (1);
	result = 0;
	while (*word >= '0' && *word <= '9')
	{
		result = result * 10 + (*word - '0');
		word++;
		if (result < 0)
			return (1);
	}
	if (*word != '\0')
		return (1);
	*num = sign * result;
	return (0);
}
