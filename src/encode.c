// ENCODE FUNCTION TAKES FILE OF SYMBOLS AND CREATES SINUSOIDAL GRAPH DEPENDS ON IT

#include "main.h"

void	encode(t_screen *screen) 
{
	int	z_x = 20;
	int	z_y = 500;

	// DRAWING THE X AXIS
	draw_line_dda(screen->img, z_x, z_y, screen->width, z_y, 0x00ff00);
	
	// DRAWING THE Y AXIS
	draw_line_dda(screen->img, z_x, 0, z_x, z_y, 0x00FF00);

	mlx_put_image_to_window(screen->mlx, screen->win, screen->img->img, 0, 0);
}