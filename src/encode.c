// ENCODE FUNCTION TAKES FILE OF SYMBOLS AND CREATES SINUSOIDAL GRAPH DEPENDS ON IT

#include "main.h"

void	draw_sine_chunk(int	chunk_sx, int chunk_size,  int z_y,int flag, t_screen *s) 
{
	float x = 0;
	int	y = 0;

	int	old_x = chunk_sx;
	int old_y = z_y;

	while (x < chunk_size)
	{
		// MINUS FOR THE CORRECT GRAPH FOR SCREEN
		y = -100 * sin(2 * PI * x / chunk_size);
		if (flag == 1 && y > 0)
			y = -y;
		if (flag == 0 && y < 0)
			y = -y;

		// DRAWING THE LINE
		draw_line_dda(s->img,old_x,old_y,x + chunk_sx,y + z_y,0x00ff0000);
		old_x = x + chunk_sx;
		old_y = y + z_y;
		x+=0.05;
		mlx_put_image_to_window(s->mlx, s->win, s->img->img, 0, 0);
	}	
}

void	fill(int x, int y, t_screen *screen) 
{
	int i = 0;

	while (i < 10)
	{
		my_pixel_put(screen->img, x, y + i, 0x00ff0000);
		my_pixel_put(screen->img, x, y - i, 0x00ff0000);
		i++;
	}
}

void	encode(t_screen *screen) 
{
	int	z_x = 20;
	int	z_y = 500;

	float	x = z_x;

	// CHUNK STEPS

	int	c_x = (WIDTH - z_x) / chunks_total(screen->bin_data);
	
	// DRAWING THE X AXIS
	draw_line_dda(screen->img, z_x, z_y, screen->width, z_y, 0x0000ff00);
	
	// DRAWING THE Y AXIS
	draw_line_dda(screen->img, z_x, 0, z_x, z_y, 0x0000FF00);

	int i = 0;
	int flag = 0;

	// GOING THROUGH THE FILE AND DRAWING THE SINE CHUNKS
	while (screen->bin_data[i])
	{
		if (screen->bin_data[i] == '1')
			flag = 1;
		else
			flag = 0;
		if (screen->bin_data[i] == '\n')
			i++;
		
		// DRAWING THE SINE CHUNK
		draw_sine_chunk(x,c_x,z_y,flag,screen);
		// FILING FOR THE METRICS
		fill(x, z_y,screen);

		// GOING TO THE NEXT CHUNK
		x += c_x;
		i++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img->img, 0, 0);
}