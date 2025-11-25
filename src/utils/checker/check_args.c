#define RT "rt"

#include "libft.h"

static int	check_file_extension(char *str);

// Checking arguments for correct input
// Return 0 if the first argument is .rt file
// Return 1 in other scenarious
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
