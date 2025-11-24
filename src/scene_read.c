#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "main.h"
#include "libft.h"
#include "parser/parse.h"
#include "utils/print/print.h"

static int		open_file(char *fname);
static int		init_scene(t_scene *scene);
// void	parse_line(t_scene *scene, char *line);

// Read scene elements from file
int	read_scene(t_scene *scene, char *fname)
{
	int		fd;
	char	*line;

	fd = open_file(fname);
	if (init_scene(scene))
		return (1);

	line = get_next_line(fd);
	while (line)
	{
		scene->line = line;
		parse_line(scene, line);
		free(line);
		line = get_next_line(fd);
	}
	scene->line = NULL;
	ft_putstr_fd("\n", 0);
	print_scene(scene);

	close(fd);
	return (0);
}

// Initialise scene struct
static int init_scene(t_scene *scene)
{
	scene->height = HEIGHT;
	scene->width = WIDTH;
	scene->camera = NULL;
	scene->a_light = NULL;
	scene->light = NULL;
	scene->plane = NULL;
	scene->cyl = NULL;
	scene->sphere = NULL;
	scene->line = NULL;
	scene->image = malloc(scene->width * scene->height * sizeof(int32_t));
	if (scene->image == NULL)
		return (1);
	return (0);
}

// Open file for read
static int	open_file(char *fname)
{
	int	fd;

	if (fname == NULL)
	{
		ft_putstr_fd("open_file(): NULL input\n", 2);
		exit(1);
	}
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(fname, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	return (fd);
}
