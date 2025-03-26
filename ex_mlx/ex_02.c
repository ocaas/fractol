
#include <mlx.h>
#include <stdlib.h>

#define KEY_ESC 65307

int des_wind(int keycode,void *parm)
{
	(void)parm;
	if (keycode == KEY_ESC)
		exit(0);
	return 0;
}

int main (void)
{
	void *mlx;
	void *wind;

	mlx = mlx_init();
	wind = mlx_new_window(mlx, 600, 500, "window");

	mlx_key_hook(wind, des_wind, NULL);
	mlx_loop(mlx);
	return 0;
}