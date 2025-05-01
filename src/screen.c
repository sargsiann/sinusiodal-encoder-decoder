#include "main.h"
#include "stb_image_write.h"


int	key_hook(int keycode, t_screen *screen) 
{
	if (keycode == 65307) // ESC key
	{
		save_to_file(screen);
		free_screen(screen);
		exit(0);
	}
	return (0);
}

void	init_screen(t_screen *screen) 
{
	// Initialize the screen structure
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, screen->width, screen->height, "Screen");
	screen->img = safe_malloc(sizeof(t_image));
	screen->img->img = mlx_new_image(screen->mlx, screen->width, screen->height);
	screen->img->address = mlx_get_data_addr(screen->img->img, &screen->img->bpp, &screen->img->line_size, &screen->img->endian);
	// KEY HOOK FOR ESC
	mlx_key_hook(screen->win, &key_hook, screen);
}

void	save_to_file(t_screen *screen) 
{
	int channels = 4;
	int width = screen->width;
	int height = screen->height;

	// SAVEING IMAGE TO BMP FILE BY STB LIBRARY
	int res = stbi_write_bmp("output.bmp", width, height, channels, screen->img->address);
	if (!res)
		exit_error("Failed to save image\n");
	printf("Image saved as output.bmp\n");
}

