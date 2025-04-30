#include "main.h"

void	free_screen(t_screen *screen) 
{
	mlx_destroy_image(screen->mlx, screen->img->img);
	safe_free(screen->img);
	safe_free(screen->bin_data);
	safe_free(screen->image_to_parse);
	mlx_clear_window(screen->mlx, screen->win);
	free(screen->mlx);
	safe_free(screen);
}