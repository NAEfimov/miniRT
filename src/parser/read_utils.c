#include "parser/read.h"
#include "parser/parse.h"
#include "libft.h"

#define COMMA_CHAR	','
#define COMMAS_NUM	2

/**
 * Checks if a string contains exactly the required number of commas.
 *
 * @param str The input string to check
 *
 * @return 0 if valid, 1 if invalid
 *
 */
int	cheack_commas(char *str)
{
	int	res;

	if (!str)
		return (1);
	res = 0;
	while(*str)
	{
		if (*str == COMMA_CHAR)
			++res;
		++str;
	}
	if (res != COMMAS_NUM)
		return (1);
	return (0);
}

/**
 * Parses the sign from the beginning of a string.
 *
 * @param pp Pointer to the string pointer to advance
 *
 * @return 1 for positive, -1 for negative
 *
 */
int	read_sign(char **pp)
{
	if (**pp == '-')
	{
		(*pp)++;
		return (-1);
	}
	else if (**pp == '+')
	{
		(*pp)++;
	}
	return (1);
}
