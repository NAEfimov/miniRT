#include "parser/read.h"
#include "parser/parse.h"
#include "libft.h"

int	last_char_is_delim(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i > 0 && str[i - 1] == VEC_DELIMETER)
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
