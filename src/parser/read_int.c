#include "parser/read.h"

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
