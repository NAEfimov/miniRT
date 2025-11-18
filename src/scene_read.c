#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "main.h"
#include "libft.h"

int		open_file(char *fname);
int		init_scene(t_scene *scene);
void	skip_whitespaces(char **str_ptr)
{
	while (**str_ptr == ' ' || **str_ptr == '\t')
		++(*str_ptr);
}

int	read_scene(t_scene *scene, char *fname)
{
	int		fd;
	char	*line;
	char	*w_line;

	fd = open_file(fname);
	if (init_scene(scene))
		return (1);
	
	line = get_next_line(fd);
	while (line)
	{
		w_line = line;
		skip_whitespaces(&w_line);
		if (*w_line != '\n' && *w_line != '\0')
		{
			ft_putstr_fd(w_line, 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	ft_putstr_fd("\n", 0);

	close(fd);
	return (0);
}

int init_scene(t_scene *scene)
{
	scene->height = HEIGHT;
	scene->width = WIDTH;
	scene->camera = NULL;
	scene->a_light = NULL;
	scene->light = NULL;
	scene->plane = NULL;
	scene->plane_num = 0;
	scene->cyl = NULL;
	scene->cyl_num = 0;
	scene->sphere = NULL;
	scene->sphere_num = 0;
	scene->image = malloc(scene->width * scene->height * sizeof(int32_t));
	if (scene->image == NULL)
		return(1);
	return (0);
}

int open_file(char *fname)
{
	int fd;	

	if (fname == NULL)
	{
		ft_putstr_fd("open_file(): NULL input", 2);
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
