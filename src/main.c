/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 01:36:59 by olopez-s          #+#    #+#             */
/*   Updated: 2025/05/02 05:01:50 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_data	fractol;

	if (ac != 2)
	{
		write(2, "Usage: ./fractol mandelbrot | julia\n", 37);
		return (1);
	}
	if (!ft_strcmp(av[1], "mandelbrot"))
		fractol.fractal_type = MANDELBROT;
	else if (!ft_strcmp(av[1], "julia"))
		fractol.fractal_type = JULIA;
	else
	{
		write(2, "Invalid fractal type.\n", 22);
		return (1);
	}
	if (error_check(&fractol))
		return (1);
	fractol.zoom      = 1.0;
	fractol.offset_x  = -0.5;
	fractol.offset_y  =  0.0;
	fractol.max_iter  = 100;
	fractol.color_shift = 0;
	ft_render(&fractol);
	handles(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}




/*
int	main(void)
{
	t_data	fractol;

	fractol.mlx = mlx_init();
	if (error_check(&fractol) == MLX_ERROR)
		return (MLX_ERROR);
	fractol.fractal_type = -1;
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "window");
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	fractol.addr = mlx_get_data_addr(fractol.img, &fractol.bpp,
			&fractol.line_len, &fractol.endian);
	handles(&fractol);
	fractol.zoom = 1.0;
	fractol.offset_x = -0.5;
	fractol.offset_y = 0.0;
	fractol.max_iter = 100;
	fractol.fractal_type = MANDELBROT;
	ft_render(&fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_key_hook(fractol.win, key_handle, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}




int	main(int ac, char **av)
{
	t_data *data;
	
	if(init(&data) == MLX_ERROR)
		return(MLX_ERROR);	
	data.fractal_type = -1;
	parse_arguments(&data, argc, argv);
	if (data.fractal_type == -1)
	{
		write(1,
			"Uso: ./fractol [mandelbrot | julia [c_real c_imag]",
			61);
		return (1);
	}
	ft_render(&data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop(data.mlx);
	return (0);
}
*/
