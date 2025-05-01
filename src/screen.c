#include "main.h"
#include "stb_image_write.h"


int	key_hook(int keycode, t_screen *screen) 
{
	if (keycode == 65307) // ESC key
	{
		if (strcmp(screen->operation,"encode") == 0) {
			save_to_file(screen);
			free_screen(screen);
		}
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

// ARGB -> RGBA

void	get_bi_buffer(t_screen *screen) {
	char *r = screen->img->address;
	char *dest;
	char *new;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			dest = &r[i * screen->img->line_size + j * 4];
			unsigned char tmp = dest[0];  // ALPHA
			unsigned char red = dest[1]; // RED
			unsigned char  green = dest[2]; // GREEN
			unsigned char  blue = dest[3]; // BLUE

			dest[0] = red; // RED
			dest[1] = green; // GREEN
			dest[2] = blue; // BLUE
			dest[3] = tmp; // ALPHA

		}
	}
}

void	get_li_buffer(t_screen *screen) {
	char *r = screen->img->address;
	char *dest;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			dest = &r[i * screen->img->line_size + j * 4];
			
			unsigned char temp = dest[0];  // Blue
			dest[0] = dest[2];             // Red
			dest[2] = temp;                // Blue ← Red
		}
	}
}


void	save_to_file(t_screen *screen) 
{
	int		channels = 4;
	int		width = screen->width;
	int		height = screen->height;
	char	*buffer;

	// SAVEING IMAGE TO BMP FILE BY STB LIBRARY

	// STB SAVES IN FORMAT RGBA 

	// ENDIAN 0 -> BGRA  BGRA -> RGBA swapping b and r
	if (screen->img->endian == 0)
		get_li_buffer(screen);
	else if (screen->img->endian == 1)
		get_bi_buffer(screen);
		
	int res = stbi_write_bmp("output.bmp", width, height, channels, screen->img->address);
	if (!res)
		exit_error("Failed to save image\n");
	printf("Image saved as output.bmp\n");
}
