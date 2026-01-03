#include "parser/read.h"

static void	parse_int_part(double *result, char **ptr);
static void	parse_fractal_part(double *result, char **ptr);

/**
 * Parses a string into a double value.
 *
 * @param num Pointer to the double to store the parsed value
 * @param ptr The input string to parse
 *
 * @return 0 on success, 1 on failure
 *
 */
int	read_double(double *num, char *ptr)
{
	int		sign;
	double	result;

	if (!ptr || !*ptr || !num)
		return (1);
	sign = read_sign(&ptr);
	if ((*ptr < '0' || *ptr > '9') && *ptr != '.')
		return (1);
	result = 0.0;
	parse_int_part(&result, &ptr);
	parse_fractal_part(&result, &ptr);
	if (*ptr != '\0')
		return (1);
	*num = sign * result;
	return (0);
}

static void	parse_int_part(double *result, char **ptr)
{
	while (**ptr >= '0' && **ptr <= '9')
	{
		*result = *result * 10.0 + (**ptr - '0');
		(*ptr)++;
	}
}

static void	parse_fractal_part(double *result, char **ptr)
{
	double	frac;
	double	div;

	if (**ptr == '.')
	{
		(*ptr)++;
		frac = 0.0;
		div = 1.0;
		while (**ptr >= '0' && **ptr <= '9')
		{
			frac = frac * 10.0 + (**ptr - '0');
			div *= 10.0;
			(*ptr)++;
		}
		*result += frac / div;
	}
}
