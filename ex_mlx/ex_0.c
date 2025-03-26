
#include <mlx.h>

int main (void)
{
	void	*mlx;
	void	*wind;

	mlx = mlx_init();
	wind = mlx_new_window(mlx, 640, 480, "window");
	mlx_loop(mlx);
	return 0;
}