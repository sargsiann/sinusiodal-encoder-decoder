#include "main.h"

void	free_screen(t_screen *screen) 
{
	mlx_destroy_image(screen->mlx, screen->img->img);
	safe_free(screen->img);
	safe_free(screen->bin_data);
	mlx_destroy_window(screen->mlx,screen->win);
	mlx_destroy_display(screen->mlx);
	safe_free(screen);
}