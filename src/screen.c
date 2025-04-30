#include "main.h"

int	key_hook(int keycode, t_screen *screen) 
{
	if (keycode == 65307) // ESC key
	{
		free_screen(screen);
		exit(0);
	}
	return (0);
}

void	init_screen(t_screen *screen) 
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, screen->width, screen->height, "Screen");
	screen->img = safe_malloc(sizeof(t_image));
	screen->img->img = mlx_new_image(screen->mlx, screen->width, screen->height);
	screen->img->address = mlx_get_data_addr(screen->img->img, &screen->img->bpp, &screen->img->line_size, &screen->img->endian);
	mlx_key_hook(screen->win, &key_hook, screen);
}


//  FUTURE UTIL FOR SAVEING IMAGE TO FILE

void	save_image(t_screen *screen) 
{
	int		fd = 0;
	char	*filename = "image.ppm";
	int		i = 0;
}