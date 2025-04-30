#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include "mlx.h"
# include <string.h>
# include <limits.h>


void	exit_error(const char *err);

typedef	struct	s_image {
	int		bpp;
	int		line_size;
	int		endian;
	char	*address;
}	t_image;

typedef struct	s_screen {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*operation;
	char	*filename;
	t_image	*img;
}	t_screen;

t_screen	*parse(char **argv);
void		*safe_malloc(size_t size);
void		*safe_calloc(size_t count, size_t size);


#endif