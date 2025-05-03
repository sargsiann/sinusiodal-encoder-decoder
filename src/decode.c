// DECODE TAKES THE IMAGE OF SINUSOIDAL GRAPH AND ANALYZES IT

# define STB_IMAGE_IMPLEMENTATION
#include "main.h"
#include "stb_image.h"

// FUNC FOR DECODING THE FILE

void get_bytes(unsigned char *data, int width, int height, int channels) {
	unsigned char r1 = 0;
	unsigned char r0 = 0;
	unsigned char old_r1 = 0;
	unsigned char old_r0 = 0;
	int	one_c = 0;
	int	zero_c;
	int	x;

	while (x < width)
	{
		// GOING THROUGH ONE LINE

		// CHECKING UPPER PART FOR 1 (OUR AMPLITUDE OF SINE IS 100)
		r1 = data[(401 * width + x) * 4];

		// CHECKING LOWER PART FOR 0 
		r0 = data[(599 * width + x) * 4];

		// CHECKING FOR TWO POINTS THAT EQUAL AND LAST NEIGBHOUR IS BLACK TO OUR AMPLITUDE (IT MEANS WE HAVE 1)
		if (r1 == 255 && old_r1 == 0)
		{
			one_c++;
			if (one_c % 2 == 0)
				printf("1");
		}
		// SO DO FOR 0 S
		if (r0 == 255 && old_r0 == 0)
		{
			zero_c++;
			if (zero_c % 2 == 0)
				printf("0");
		}
		old_r1 = r1;
		old_r0 = r0;
		x++;
	}	
}

void	decode(t_screen *screen)
{
	printf("DECODEING ...\n");

	// GETIING WIDTH HEIGHT AND CHANNELS OF LOADING IMAGE MUST BE PNG
	int	w;
	int	h;
	int	c;
	unsigned char *pixel_data = stbi_load(screen->image_to_parse,&w,&h,&c,0);
	
	// GETTING THE HIDDEN BYTES BY THE GRAPH
	get_bytes(pixel_data,w,h,c);

	// FREEING THE IMAGE
	stbi_image_free(pixel_data);
}