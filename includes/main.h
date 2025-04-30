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
# include <math.h>

# define BUFFER_SIZE 1024
# define WIDTH 800
# define HEIGHT 600
# define PI 3.14

void	exit_error(const char *err);

typedef	struct	s_image {
	void	*img;
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
	char	*image_to_parse;
	char	*bin_data;
	t_image	*img;
}	t_screen;

void		parse(char **argv);
void		*safe_malloc(size_t size);
void		*safe_calloc(size_t count, size_t size);
void		init_screen(t_screen *screen);
void		safe_free(void *ptr);
void		free_screen(t_screen *screen);
void		encode(t_screen *screen);
void		draw_line_dda(t_image *img, int x0, int y0, int x1, int y1, int color);
void		my_pixel_put(t_image *img, int x, int y, int color);

#endif