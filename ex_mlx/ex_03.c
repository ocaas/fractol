
#include <mlx.h>
#include <stdlib.h>

#define KEY_ESC 65307

typedef struct t_data
{
	void *mlx;
	void *wind;
	void *img;
	char *addr;
	int bpp;
	int line_len;
	int edian;
}t_data;

int esc(int keycode, void *param)
{
	(void)param;
	if (keycode == KEY_ESC)
		exit(0);
	return 0;
}

void drawline(t_data *img, int x0, int y0, int x1, int y1, int color)
{
	//find diff
	int	dx, dy, sx, sy, err, e2;
	
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);

	if (x0 < x1)
        sx = 1;
    else
        sx = -1;

    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
	err = dx -dy;
    
	while (x0 != x1 || y0 != y1)
	{
		// Better: use draw_col() if you're writing to an image!
		char *dst = img->addr + (y0 * img->line_len + x0 * (img->bpp / 8));
		*(unsigned int *)dst = color;


		e2 = 2 * err;

		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}

}

int main(void)
{
	t_data img;

	img.mlx = mlx_init();
	img.wind = mlx_new_window(img.mlx, 700, 800, "window");

	img.img = mlx_new_image(img.mlx, 600, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.edian);

	drawline(&img, 50, 50, 300, 300, 0xFFC0CB);

	mlx_put_image_to_window(img.mlx, img.wind, img.img, 0, 0);

	mlx_key_hook(img.wind, esc, NULL);
	mlx_loop(img.mlx);

	return 0;
}
