#include "./parser/read.h"
#include "./parser/parse.h"

int	read_color(t_color *color, char *word)
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
		read_uint8(&(color->r), words[0]) ||
		read_uint8(&(color->g), words[1]) ||
		read_uint8(&(color->b), words[2]))
	{
		clean_words(words);
		return (1);
	}
	clean_words(words);
	return (0);
}
