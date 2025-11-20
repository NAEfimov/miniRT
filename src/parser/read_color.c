#include "./parser/read.h"

#define DELIMETER ','

int	read_color(t_color *color, char *word)
{
	char	**words;
	size_t	size;

	words = ft_split(word, DELIMETER);
	if (!words)
		return (1);

	size = 0;
	while (words[size])
		++size;
	
	if (size != 3)
		return (1);

	if (read_uint8(&(color->r), words[0]) ||
		read_uint8(&(color->g), words[1]) ||
		read_uint8(&(color->b), words[2]))
	{
		return (1);
	}
	clean_words(words);
	return (0);
}
