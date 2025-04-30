#include "main.h"

// PUTS PIXEL TO IMAGE

void	draw_line_dda(t_image *img, int x0, int y0, int x1, int y1, int color) 
{
	// FINDING THE DIFFERENCE BETWEEN THE TWO POINTS
	int	dx = x1 - x0;
	int	dy = y1 - y0;

	// FINDING THE MAXIMUM NUMBER OF STEPS
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	// FINDING THE INCREMENTAL VALUES

	float x_inc = (float)dx / steps;
	float y_inc = (float)dy / steps;

	// DRAWING THE LINE
	for (int i = 0; i <= steps; i++) 
	{
		// MAKING INTEGER VALUES FOR THE PIXEL
		int x = (int)(x0 + i * x_inc);
		int y = (int)(y0 + i * y_inc);
		my_pixel_put(img, x, y, color);
	}
}

void	my_pixel_put(t_image *img, int x, int y, int color) 
{
	char	*dst;

	// IF INSIDE THE BOUNDS
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;

	dst = img->address + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}