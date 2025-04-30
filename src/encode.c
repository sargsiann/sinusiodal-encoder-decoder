// ENCODE FUNCTION TAKES FILE OF SYMBOLS AND CREATES SINUSOIDAL GRAPH DEPENDS ON IT

#include "main.h"

void	encode(t_screen *screen) 
{
	int	z_x = 20;
	int	z_y = 500;

	float	x = 0;
	float	y = 0;

	// DRAWING THE X AXIS
	draw_line_dda(screen->img, z_x, z_y, screen->width, z_y, 0x00ff00);
	
	// DRAWING THE Y AXIS
	draw_line_dda(screen->img, z_x, 0, z_x, z_y, 0x00FF00);

	mlx_put_image_to_window(screen->mlx, screen->win, screen->img->img, 0, 0);

	// DRAWING JUST SINE

	int	old_x = 0;
	int	old_y = 0;
	while (x < WIDTH - z_x)
	{
		y = sin(x/7);
		x += 0.1;
		draw_line_dda(screen->img,old_x + z_x,old_y,(int)(z_x + x),(int)(z_y - y * 10),0xff0000);
		mlx_put_image_to_window(screen->mlx, screen->win, screen->img->img, 0, 0);
		old_x = (int )x;
		old_y =	(int)(z_y - y * 10);
	}
}