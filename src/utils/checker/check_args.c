#define RT "rt"

#include "libft.h"

static int	check_file_extension(char *str);

/**
 * Checks command line arguments for correct input.
 * Validates that exactly one argument is provided and it has a .rt extension.
 *
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 */
void	check_args(int argc, char **argv)
{
	if (argc <= 1)
	{
		ft_putstr_fd("Error: too less argumets\n", 2);
		exit(1);
	}
	if (check_file_extension(argv[1]))
	{
		ft_putstr_fd("Error: wrong file extension\n", 2);
		exit(1);
	}
}

/**
 * Checks if the file extension is .rt.
 *
 * @param str Filename string to check
 *
 * @return 0 if extension is .rt, 1 otherwise
 */
static int	check_file_extension(char *str)
{
	char	*ext_ptr;

	ext_ptr = NULL;
	while (*str)
	{
		if (*str == '.')
			ext_ptr = str + 1;
		++str;
	}
	if (ext_ptr == NULL)
		return (1);
	if (ft_strcmp(ext_ptr, RT))
		return (1);
	return (0);
}
