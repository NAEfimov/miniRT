#include "./parser/read.h"
#include "./parser/parse.h"
#include "libft.h"


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
	
	if (size != 3 ||
		read_double(&(vec->x), words[0]) ||
		read_double(&(vec->y), words[1]) ||
		read_double(&(vec->z), words[2]))
	{
		clean_words(words);
		return (1);
	}
	clean_words(words);
	return (0);
}
