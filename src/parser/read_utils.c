#include "parser/read.h"
#include "parser/parse.h"
#include "libft.h"

#define COMMA_CHAR	','
#define COMMAS_NUM	2

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
