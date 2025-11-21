#include "parser/read.h"
#include "parser/parse.h"
#include "libft.h"
// #include <stdio.h>

int	read_vec(t_vec *vec, char *word)
{
	char	**words;
	size_t	size;

	if (last_char_is_delim(word))
		return (1);
	words = ft_split(word, VEC_DELIMETER);
	if (!words)
		return (1);

	size = 0;
	while (words[size])
		++size;
	// printf("words count: %ld\n", size);

	if (size != 3 ||
		read_double(&(vec->x), words[0]) ||
		read_double(&(vec->y), words[1]) ||
		read_double(&(vec->z), words[2]))
	{
		clean_words(words);
		return (1);
	}
	clean_words(words);
	// ft_putstr_fd("vec was readed\n", 0);
	// printf("Vec was readed: %f, %f, %f\n", vec->x, vec->y, vec->z);
	return (0);
}
