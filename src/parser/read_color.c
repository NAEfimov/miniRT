#include "parser/read.h"
#include "parser/parse.h"

int	read_color(t_vec *color, char *word)
{
	char		**words;
	t_rgb_color c;

	if (!color || !word || cheack_commas(word))
		return (1);
	words = ft_split(word, VEC_DELIMETER);
	if (!words)
		return (1);
	if (split_size(words) != 3
		|| read_uint8(&(c.r), words[0])
		|| read_uint8(&(c.g), words[1])
		|| read_uint8(&(c.b), words[2]))
	{
		clean_words(words);
		return (1);
	}
	color->x = (double)c.r / 255.0;
	color->y = (double)c.g / 255.0;
	color->z = (double)c.b / 255.0;
	clean_words(words);
	return (0);
}
