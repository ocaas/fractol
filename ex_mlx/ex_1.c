
#include <mlx.h>
#include <stdlib.h>

#define ESC_KEY 65307

int close_wind(int keycode, void *parameter)
{
	(void)parameter;
	
	if (keycode == ESC_KEY)
		exit(0);
	return 0;
}

int main()
{
	void *mlx;
	void *wind;
	
	mlx = mlx_init();
	wind = mlx_new_window(mlx, 600, 500, "window");
	
	mlx_key_hook(wind, close_wind, NULL);
	mlx_loop(mlx);

	return 0;
}