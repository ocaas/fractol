
#include <mlx.h>
#include <stdlib.h>

#define KEY_ESC 65307

typedef	struct t_data
{
	void *mlx;
	void *wind;
	void *img;
	char *addr; //pointer to the image date
	int	bpp; //bits per pixel(color depth) HORIZONTAL
	int	line_len; //how many bytes each row of pixels takes in memory VERTICAL
	int	edian; //byte order??
}t_data;

int	draw_col(t_data *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_len + x * (data->bpp/ 8));
	*(unsigned int*)dest = color;
}
/*this function finds the memory location of the pixel and writes the 
color value at this location BOOMSHAKALAKA*/

int des_wind(int keycode,void *parm)
{
	(void)parm;
	if (keycode == KEY_ESC)
		exit(0);
	return 0;
}

int main (void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.wind = mlx_new_window(img.mlx, 600, 500, "window");

	img.img = mlx_new_image(img.mlx, 600, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.edian);

	draw_col(&img, 320, 420, 0xFFC0CB);
	mlx_put_image_to_window(img.mlx, img.wind, img.img, 0, 0);

	mlx_key_hook(img.wind, des_wind, NULL);
	mlx_loop(img.mlx);
	return 0;
}