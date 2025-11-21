#include "./parser/read.h"
#include <stdio.h>

int	read_int(int *num, char *word)
{
	int sign;
	int result;

	if (!word || !*word || !num)
		return (1);

	sign = read_sign(&word);
	// printf("Sign was readed: %d\n", sign);
	// printf("Word: '%s'\n", word);
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
	// printf("Int was readed: %d\n", *num);
	return (0);
}
